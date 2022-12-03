#include "status.h"
#include "print.h"

#define ERROR_MASK 0x8000000000000000

static char16_t* errors[] = {
    L"Load error",
    L"Invalid parameter",
    L"Unsupported",
    L"Bad buffer size",
    L"Buffer to small",
    L"Not ready",
    L"Device Error",
    L"Write protected",
    L"Out of resources",
    L"Volume corrupted",
    L"Volume full",
    L"No media",
    L"Media changed",
    L"Not found",
    L"Access denied",
    L"No response",
    L"No mapping"
    L"Timeout",
    L"Not started",
    L"Already started",
    L"Aborted",
    L"ICMP error",
    L"TFTP error",
    L"Protocol error",
    L"Incompatible version",
    L"Security violation",
    L"CRC error",
    L"End of media",
    L"End of file",
    L"Invalid language",
    L"Compromised data",
    L"IP address conflict",
    L"HTTP error"
};

char16_t* warnings[] = {
    L"Unknown glyph",
    L"Delete failure",
    L"Write failure",
    L"Buffer too small",
    L"Stale Data",
    L"File system",
    L"Reset required"
};

bool is_error(size_t status) {
    return (status & ERROR_MASK) != 0;
}

bool is_warning(size_t status) {
    return status != 0 && (status & ERROR_MASK) == 0;
}

char16_t *str_status(size_t status) {
    if(status == 0) {
        return L"Success";
    } else if(is_error(status)) {
        status = (status & ~ERROR_MASK) - 1;
        if(status < 28)
            return errors[status];
        else if(status < 35)
            return errors[status - 3];
        else
            return L"Unknown error";
    } else {
        status -= 1;
        if(status < 7)
            return warnings[status];
        else
            return L"Unknown warning";
    }
}
