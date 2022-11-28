#pragma once

#include "types.h"
#include "table_header.h"
#include "guid.h"

#define EFI_OPEN_PROTOCOL_BY_HANDLE 0x1

typedef struct EfiBootServices {
    EfiTableHeader header;
    void           *raise_tpl;
    void           *restore_tpl;
    void           *allocate_pages;
    void           *free_pages;
    void           *get_memory_map;
    void           *allocate_pool;
    void           *free_pool;
    void           *create_event;
    void           *set_timer;
    void           *wait_for_event;
    void           *signal_event;
    void           *close_event;
    void           *check_event;
    void           *install_protocol_interface;
    void           *reinstall_protocol_interface;
    void           *uninstall_protocol_interface;
    void           *handle_protocol;
    void           *reserved;
    void           *register_protocol_notify;
    void           *locate_handle;
    void           *locate_devicePath;
    void           *install_configuration_table;
    void           *load_image;
    void           *start_image;
    size_t         (*exit)(EfiHandle, size_t, size_t, char16_t*);
    void           *unload_image;
    size_t         (*exit_boot_services)(EfiHandle, size_t);
    void           *get_next_monotonic_count;
    void           *stall;
    void           *set_watchdog_timer;
    void           *connect_controller;
    void           *disconnect_controller;
    size_t         (*open_protocol)(
                        EfiHandle,
                        const Guid*,
                        void**,
                        EfiHandle,
                        EfiHandle,
                        uint32_t
                   );
    size_t         (*close_protocol)(EfiHandle, Guid*, EfiHandle, EfiHandle);
    void           *open_protocol_information;
    void           *protocols_per_handle;
    void           *locate_handle_buffer;
    void           *locate_protocol;
    void           *install_multiple_protocol_interfaces;
    void           *uninstall_multiple_protocol_interfaces;
    void           *calculate_crc32;
    void           *copy_mem;
    void           *set_mem;
    void           *create_event_ex;
} EfiBootServices;
