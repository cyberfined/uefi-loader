#pragma once

#include "types.h"

bool is_error(size_t status);
bool is_warning(size_t status);
char16_t *str_status(size_t status);
size_t error_code(size_t status);

// Errors
#define EfiLoadError           1
#define EfiInvalidParameter    2
#define EfiUnsupported         3
#define EfiBadBufferSize       4
#define EfiBufferTooSmall      5
#define EfiNotReady            6
#define EfiDeviceError         7
#define EfiWriteProtected      8
#define EfiOutOfResources      9
#define EfiVolumeCorrupted     10
#define EfiVolumeFull          11
#define EfiNoMedia             12
#define EfiMediaChanged        13
#define EfiNotFound            14
#define EfiAccessDenied        15
#define EfiNoResponse          16
#define EfiNoMapping           17
#define EfiTimeout             18
#define EfiNotStarted          19
#define EfiAlreadyStarted      20
#define EfiAborted             21
#define EfiIcmpError           22
#define EfiTftpError           23
#define EfiProtocolError       24
#define EfiIncompatibleVersion 25
#define EfiSecurityViolation   26
#define EfiCrcError            27
#define EfiEndOfMedia          28
#define EfiEndOfFile           31
#define EfiInvalidLanguage     32
#define EfiCompromisedData     33
#define EfiIpAddressConflict   34
#define EfiHttpError           35

// Warnings
#define EfiWarnUnknownGlyph   1
#define EfiWarnDeleteFailure  2
#define EfiWarnWriteFailure   3
#define EfiWarnBufferTooSmall 4
#define EfiWarnStaleData      5
#define EfiWarnFileSystem     6
#define EfiWarnResetRequired  7
