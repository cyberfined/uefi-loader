#include "types.h"
#include "globals.h"
#include "boot_services.h"
#include "system_table.h"
#include "proto/loaded_image.h"
#include "proto/volume.h"
#include "print.h"
#include "exit.h"

#define handle_error(err) do { \
    puts(L"Something went wrong"); \
    exit(2); \
} while(0)

size_t efi_main(EfiHandle handle, EfiSystemTable *system_table) {
    init_image_handle(handle);
    init_system_table(system_table);

    puts(L"Open loaded image protocol");

    EfiBootServices *boot_services = system_table->boot_services;
    EfiLoadedImage *loaded_image;
    size_t err = boot_services->open_protocol(
        handle,
        &EFI_LOADED_IMAGE_PROTOCOL_GUID,
        (void**)&loaded_image,
        handle,
        NULL,
        EFI_OPEN_PROTOCOL_BY_HANDLE
    );
    if(err != 0)
        handle_error(err);

    puts(L"Open volume protocol");

    EfiVolume *volume;
    err = boot_services->open_protocol(
        loaded_image->device_handle,
        &EFI_VOLUME_PROTOCOL_GUID,
        (void**)&volume,
        handle,
        NULL,
        EFI_OPEN_PROTOCOL_BY_HANDLE
    );
    if(err != 0)
        handle_error(err);

    puts(L"Open filesystem");
    EfiFileSystem *file_system;
    err = volume->open_volume(volume, &file_system);
    if(err != 0)
        handle_error(err);

    puts(L"Open test.txt");
    EfiFile *file;
    err = file_system->open(file_system, &file, L"test.txt", MODE_READ, 0);
    if(err != 0)
        handle_error(err);

    puts(L"test.txt content:");
    size_t n_bytes;
    char16_t buf[1024];
    err = file->read(file, &n_bytes, (uint8_t*)buf);
    if(err != 0)
        handle_error(err);
    puts(buf);

    return 0;
}
