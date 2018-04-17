#pragma once

#include <cstdio>
#include <iostream>
#include <memory>
#include <string>

#include "scheme_object.h"

class Shell {
private:
    bool is_fixnum(std::unique_ptr<scheme_object>);
    bool is_delimiter(int c);
    bool is_boolean(std::unique_ptr<scheme_object>);
    bool is_false(std::unique_ptr<scheme_object>);

    int peek(std::FILE* in);

    std::unique_ptr<scheme_object> make_fixnum(long);
    std::unique_ptr<scheme_object> make_bool(bool);
    std::unique_ptr<scheme_object> read(std::FILE*);
    std::unique_ptr<scheme_object> eval(std::unique_ptr<scheme_object>);

    void init();
    void eat_whitespace(std::FILE*);
    void write(std::unique_ptr<scheme_object>);
public:
    Shell();
    void repl();
};

