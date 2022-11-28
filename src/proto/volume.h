#pragma once

#include "../types.h"
#include "file_system.h"

static Guid EFI_VOLUME_PROTOCOL_GUID =
    {0x0964e5b22,0x6459,0x11d2,
    {0x8e, 0x39, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b}};

typedef struct EfiVolume {
    uint64_t revision;
    size_t   (*open_volume)(struct EfiVolume*, EfiFileSystem**);
} EfiVolume;
