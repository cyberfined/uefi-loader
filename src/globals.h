#pragma once

#include "types.h"
#include "system_table.h"

extern EfiHandle image_handle;
extern EfiSystemTable *system_table;

void init_image_handle(EfiHandle image_handle);
void init_system_table(EfiSystemTable *system_table);
