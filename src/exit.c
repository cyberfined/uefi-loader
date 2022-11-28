#include "exit.h"

#include "globals.h"

void exit(size_t code) {
    system_table->boot_services->exit(image_handle, code, 0, NULL);
}
