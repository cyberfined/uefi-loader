#pragma once

#include "types.h"
#include "table_header.h"
#include "proto/output.h"
#include "boot_services.h"

typedef struct {
    EfiTableHeader    header;
    char16_t          *firmware_vendor;
    uint32_t          firmware_revision;
    EfiHandle         console_in_handle;
    void              *standard_input;
    EfiHandle         console_out_handle;
    EfiOutputProtocol *standard_output;
    EfiHandle         console_err_handle;
    EfiOutputProtocol *error_output;
    void              *runtime_services;
    EfiBootServices   *boot_services;
    size_t            number_of_table_entries;
    void              *configuration_table;
} EfiSystemTable;
