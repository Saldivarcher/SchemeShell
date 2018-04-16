#pragma once

class scheme_object {
public:
    typedef enum {BOOLEAN, FIXNUM} scheme_object_type;
    scheme_object_type type;
    union {
        struct {
            bool value;
        } boolean;
        struct {
            long value;
        } fixnum;
    } data;
};
