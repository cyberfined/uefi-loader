#include "types.h"
#include "globals.h"
#include "boot_services.h"
#include "system_table.h"
#include "proto/loaded_image.h"
#include "proto/volume.h"
#include "print.h"
#include "exit.h"
#include "status.h"

#define ROUNDUP(x,b) (((unsigned long)x+b-1)&(~(b-1)))
#define PAGEUP(x) ROUNDUP(x, 4096)

#define handle_error(err) do { \
    puts(str_status(err)); \
    exit(2); \
} while(0)

/*
EfiFileSystem* init_file_system() {
    puts(L"Open loaded image protocol");
    EfiBootServices *boot_services = system_table->boot_services;
    EfiLoadedImage *loaded_image;
    size_t err = boot_services->open_protocol(
        image_handle,
        &EFI_LOADED_IMAGE_PROTOCOL_GUID,
        (void**)&loaded_image,
        image_handle,
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
        image_handle,
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

    return file_system;
}
*/

EfiMemoryDescriptor* get_memory_map(size_t *map_key) {
    puts(L"Retrieve size for memory map buffer");
    size_t descriptor_size;
    uint32_t descriptor_version;
    size_t buffer_size = 0;
    size_t err = system_table->boot_services->get_memory_map(
        &buffer_size,
        NULL,
        map_key,
        &descriptor_size,
        &descriptor_version
    );
    if(err != 0)
        handle_error(err);

    puts(L"Allocate memory for memory map buffer");
    EfiMemoryDescriptor *buffer;
    buffer_size = PAGEUP(buffer_size) / 4096;
    err = system_table->boot_services->allocate_pages(
        AllocateAnyPages,
        EfiConventionalMemory,
        buffer_size,
        (uint64_t*)&buffer
    );
    if(err != 0)
        handle_error(err);

    puts(L"Retrieve memory map");
    err = system_table->boot_services->get_memory_map(
        &buffer_size,
        buffer,
        map_key,
        &descriptor_size,
        &descriptor_version
    );
    if(err != 0)
        handle_error(err);

    return buffer;
}

size_t efi_main(EfiHandle _image_handle, EfiSystemTable *_system_table) {
    image_handle = _image_handle;
    system_table = _system_table;

    printf(L"Hello, %s: 0x%x\r\n", L"world", 0xf12);

    size_t map_key;
    get_memory_map(&map_key);
    system_table->boot_services->exit_boot_services(image_handle, map_key);

    return 0;
}
