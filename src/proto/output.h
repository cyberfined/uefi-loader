#pragma once

typedef struct {
    int32_t max_mode;
    int32_t mode;
    int32_t attribute;
    int32_t cursor_column;
    int32_t cursor_row;
    bool    cursor_visible;
} EfiTextOutputMode;

typedef struct EfiOutputProtocol {
    size_t            (*reset)(struct EfiOutputProtocol*, bool);
    size_t            (*output_string)(struct EfiOutputProtocol*, const char16_t*);
    size_t            (*test_string)(struct EfiOutputProtocol*, const char16_t*);
    size_t            (*query_mode)(struct EfiOutputProtocol, size_t, size_t*, size_t*);
    size_t            (*set_attribute)(struct EfiOutputProtocol*, size_t);
    size_t            (*clear_screen)(struct EfiOutputProtocol*);
    size_t            (*set_cursor_position)(struct EfiOutputProtocol*, size_t, size_t);
    size_t            (*enable_cursor)(struct EfiOutputProtocol*, bool);
    EfiTextOutputMode *mode;
} EfiOutputProtocol;
