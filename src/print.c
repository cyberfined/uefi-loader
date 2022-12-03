#include "globals.h"
#include "types.h"

void puts(char16_t *str) {
    system_table->standard_output->output_string(
        system_table->standard_output,
        str
    );
    system_table->standard_output->output_string(
        system_table->standard_output,
        L"\r\n"
    );
}

static char16_t buf[1024];
static char16_t digits[16] = L"0123456789abcdef";

static inline size_t printint(size_t num, size_t basement, size_t buf_offset) {
    size_t len = 0;

    do {
        if(buf_offset == sizeof(buf) - 1) {
            buf[buf_offset] = 0;
            for(size_t i =  buf_offset - len, j = buf_offset - 1; i < j; i++, j--) {
                char16_t tmp = buf[i];
                buf[i] = buf[j];
                buf[j] = tmp;
            }
            system_table->standard_output->output_string(
                system_table->standard_output,
                buf
            );
            buf_offset = 0;
            len = 0;
        }

        char16_t c = digits[num % basement];
        buf[buf_offset++] = c;
        len++;
        num /= basement;
    } while(num != 0);

    if(buf_offset != 0) {
        for(size_t i = buf_offset - len, j = buf_offset - 1; i < j; i++, j--) {
            char16_t tmp = buf[i];
            buf[i] = buf[j];
            buf[j] = tmp;
        }
    }

    return buf_offset;
}

static inline size_t printstr(char16_t *str, size_t buf_offset) {
    while(*str) {
        if(buf_offset == sizeof(buf) - 1) {
            buf[buf_offset] = 0;
            system_table->standard_output->output_string(
                system_table->standard_output,
                buf
            );
            buf_offset = 0;
        }

        buf[buf_offset++] = *str++;
    }

    return buf_offset;
}

void printf(char16_t *fmt, ...) {
    bool prev_percent = false;
    size_t j = 0;

    va_list ap;
    va_start(ap, fmt);

    for(size_t i = 0; fmt[i]; i++) {
        char16_t c = fmt[i];

        if(!prev_percent) {
            if(c == L'%') {
                prev_percent = true;
            } else {
                if(j == sizeof(buf) - 1) {
                    buf[j] = 0;
                    system_table->standard_output->output_string(
                        system_table->standard_output,
                        buf
                    );
                    j = 0;
                }
                buf[j++] = c;
            }
        } else {
            switch(c) {
            case 'd':
                j = printint(va_arg(ap, size_t), 10, j);
                break;
            case 'x':
                j = printint(va_arg(ap, size_t), 16, j);
                break;
            case 's':
                j = printstr(va_arg(ap, char16_t*), j);
                break;
            }
            prev_percent = false;
        }
    }

    va_end(ap);

    if(j != 0) {
        buf[j] = 0;
        system_table->standard_output->output_string(
            system_table->standard_output,
            buf
        );
    }
}
