#include "globals.h"

EfiHandle      image_handle;
EfiSystemTable *system_table;

void init_image_handle(EfiHandle _image_handle) {
    image_handle = _image_handle;
}

void init_system_table(EfiSystemTable *_system_table) {
    system_table = _system_table;
}
