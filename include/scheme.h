#pragma once

#include <cstdio>
#include <iostream>
#include <memory>
#include <string>

typedef enum {FIXNUM} scheme_object_type;

typedef struct scheme_object {
    scheme_object_type type;
    union {
        struct {
            long value;
        } fixnum;
    } data;
} scheme_object;

class Shell {
private:
    bool is_fixnum(std::unique_ptr<scheme_object>);
    bool is_delimiter(int c);
    int peek(std::FILE* in);

    std::unique_ptr<scheme_object> make_fixnum(long);
    std::unique_ptr<scheme_object> read(std::FILE*);
    std::unique_ptr<scheme_object> eval(std::unique_ptr<scheme_object>);

    void eat_whitespace(std::FILE* in);
    void write(std::unique_ptr<scheme_object>);
public:
    void repl();
};

