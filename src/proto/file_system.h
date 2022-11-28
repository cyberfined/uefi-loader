#pragma once

#include "../types.h"
#include "file_system.h"

#define MAX_FILEPATH 256

// Open modes
#define MODE_READ   0x0000000000000001
#define MODE_WRITE  0x0000000000000002
#define MODE_CREATE 0x8000000000000000

// Attributes
#define READ_ONLY 0x01
#define HIDDEN    0x02
#define SYSTEM    0x04
#define RESERVED  0x08
#define DIRECTORY 0x10
#define ARCHIVE   0x20
#define VALID     0x37

typedef struct {
    uint64_t struct_size;
    uint64_t size;
    uint64_t physical_size;
    Time     created_at;
    Time     accessed_at;
    Time     updated_at;
    uint64_t attribute;
    char16_t filename[MAX_FILEPATH];
} EfiFileInfo;

typedef struct EfiFileSystem {
    uint64_t revision;
    size_t (*open)(
        struct EfiFileSystem*,
        struct EfiFileSystem**,
        const char16_t*,
        uint64_t,
        uint64_t
    );
    size_t (*close)(struct EfiFileSystem*);
    size_t (*delete)(struct EfiFileSystem*);
    size_t (*read)(struct EfiFileSystem*, size_t*, uint8_t*);
    size_t (*write)(struct EfiFileSystem*, size_t*, uint8_t*);
    size_t (*get_position)(struct EfiFileSystem*, uint64_t*);
    size_t (*set_position)(struct EfiFileSystem*, uint64_t);
    void   *get_info;
    void   *set_info;
    size_t (*flush)(struct EfiFileSystem*);
    void   *open_ex;
    void   *read_ex;
    void   *write_ex;
    void   *flush_ex;
} EfiFileSystem;

typedef EfiFileSystem EfiFile;
