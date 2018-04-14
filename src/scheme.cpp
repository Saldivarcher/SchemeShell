#include "scheme.h"

bool Shell::is_fixnum(std::unique_ptr<scheme_object> obj) {
    return obj->type == FIXNUM;
}

bool Shell::is_delimiter(int c) {
    return std::isspace(c) || c == EOF 
           || c == '(' || c == ')'
           || c == '"' || c == ';';
}

int Shell::peek(std::FILE* in) {
    int c;
    c = std::getc(in);
    ungetc(c, in);
    return c;
}

void Shell::eat_whitespace(std::FILE* in) {
    int c;
    while((c = std::getc(in)) != EOF) {
        if(isspace(c)) 
            continue;
        else if (c == ';') {
            while (((c = std::getc(in)) != EOF) && (c != '\n'));
            continue;
        }
        std::ungetc(c, in);
        break;
    }
}

std::unique_ptr<scheme_object> Shell::make_fixnum(long num) {
    auto obj = std::make_unique<scheme_object>();
    obj->type = FIXNUM;
    obj->data.fixnum.value = num;
    return obj;
}

std::unique_ptr<scheme_object> Shell::read(std::FILE* in) {
    int c = 0;
    short sign = 1;
    long num = 0;
    eat_whitespace(in);

    c = std::getc(in);
    if (std::isdigit(c) || (c == '-' && (std::isdigit(peek(in))))) {
        if (c == '-') sign = -1;
        else std::ungetc(c, in);
        while (std::isdigit(c = std::getc(in))) {
            num = (num * 10) + (c - '0');
        }
        num *= sign;
        if (is_delimiter(c)) {
            std::ungetc(c, in);
            return make_fixnum(num);
        }
        std::cerr << "Bad input \n";
        exit(1);
    }
    std::cerr << "Bad input \n";
    exit(1);
}

std::unique_ptr<scheme_object> Shell::eval(std::unique_ptr<scheme_object> expression) {
    return expression;
}

void Shell::write(std::unique_ptr<scheme_object> obj) {
    switch (obj->type) {
        case FIXNUM:
            std::cout << obj->data.fixnum.value;
            break;
        default:
            std::cerr << "Cannot write an unknown type\n";
            exit(1);
    }
}

void Shell::repl() {
    while(1) {
        std::cout << "> ";
        write(eval(read(stdin)));
        std::cout << "\n";
    }
}
