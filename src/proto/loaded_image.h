#pragma once

#include "../types.h"
#include "../guid.h"

static Guid EFI_LOADED_IMAGE_PROTOCOL_GUID =
    {0x5B1B31A1,0x9562,0x11d2,\
    {0x8E,0x3F,0x00,0xA0,0xC9,0x69,0x72,0x3B}};

typedef enum {
    EfiReservedMemoryType,
    EfiLoaderCode,
    EfiLoaderData,
    EfiBootServicesCode,
    EfiBootServicesData,
    EfiRuntimeServicesCode,
    EfiRuntimeServicesData,
    EfiConventionalMemory,
    EfiUnusableMemory,
    EfiACPIReclaimMemory,
    EfiACPIMemoryNVS,
    EfiMemoryMappedIO,
    EfiMemoryMappedIOPortSpace,
    EfiPalCode,
    EfiPersistentMemory,
    EfiUnacceptedMemoryType,
    EfiMaxMemoryType
} EfiMemoryType;

typedef struct {
    uint8_t type;
    uint8_t subtype;
    uint8_t length[2];
} EfiDevicePath;

typedef struct {
    uint32_t       revision;
    EfiHandle      parent_handle;
    EfiSystemTable *system_table;
    EfiHandle      device_handle;
    EfiDevicePath  *file_path;
    void           *reserved;
    uint32_t       load_options_size;
    void           *load_options;
    void           *image_base;
    uint64_t       image_size;
    EfiMemoryType  image_code_type;
    EfiMemoryType  image_data_type;
    size_t         (*unload)(EfiHandle);
} EfiLoadedImage;
