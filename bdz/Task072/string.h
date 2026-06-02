#ifndef STRING_H
#define STRING_H

typedef struct String String;

struct String {
    char* data;
    size_t size;
    size_t capacity;

    void (*append)(String* self, String* source);
    void (*push_back)(String* self, String* source);
    void (*clear)(String* self);
    size_t (*length)(String* self);
    void (*print)(String* self);
    void (*destroy)(String* self);
};

String create_string(const char *initial_str); 

#endif