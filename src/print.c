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
