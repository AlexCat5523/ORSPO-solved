#include "string_oop.h"
#include <string.h>

// Вспомогательная приватная функция для изменения размера памяти (реализует динамическое выделение)
static void reserve(String *self, size_t min_capacity) {
    if (self->capacity >= min_capacity) {
        return;
    }

    // Стратегия удвоения емкости для амортизированной сложности O(1)
    size_t new_capacity = self->capacity == 0 ? 16 : self->capacity * 2;
    if (new_capacity < min_capacity) {
        new_capacity = min_capacity;
    }

    char *new_data = (char *)realloc(self->data, new_capacity);
    if (new_data == NULL) {
        perror("Ошибка выделения памяти при реаллокации");
        exit(EXIT_FAILURE);
    }

    self->data = new_data;
    self->capacity = new_capacity;
}

// Реализация метода length
static size_t string_length(const String *self) {
    if (self == NULL) return 0;
    return self->size;
}

// Реализация метода print
static void string_print(const String *self) {
    if (self && self->data) {
        printf("%s", self->data);
    }
}

// Реализация метода clear
static void string_clear(String *self) {
    if (self && self->data) {
        self->size = 0;
        self->data[0] = '\0'; // Строка становится пустой, но память сохраняется
    }
}

// Реализация метода push_back
static void string_push_back(String *self, char c) {
    if (self == NULL) return;

    // +2 учитывает новый символ и терминирующий ноль '\0'
    reserve(self, self->size + 2);

    self->data[self->size] = c;
    self->size++;
    self->data[self->size] = '\0';
}

// Реализация метода append
static void string_append(String *self, const char *str) {
    if (self == NULL || str == NULL) return;

    size_t append_len = strlen(str);
    if (append_len == 0) return;

    // +1 для терминирующего нуля
    reserve(self, self->size + append_len + 1);

    strcpy(self->data + self->size, str);
    self->size += append_len;
}

// Реализация метода destroy
static void string_destroy(String *self) {
    if (self) {
        free(self->data);
        self->data = NULL;
        self->size = 0;
        self->capacity = 0;
    }
}

// Конструктор объекта String
String create_string(const char *initial_str) {
    String str;
    
    // Инициализация полей по умолчанию
    str.data = NULL;
    str.size = 0;
    str.capacity = 0;

    // Привязка указателей на функции к методам структуры
    str.append = string_append;
    str.push_back = string_push_back;
    str.clear = string_clear;
    str.length = string_length;
    str.print = string_print;
    str.destroy = string_destroy;

    // Если передана начальная строка, инициализируем данные
    if (initial_str != NULL) {
        size_t init_len = strlen(initial_str);
        reserve(&str, init_len + 1);
        strcpy(str.data, initial_str);
        str.size = init_len;
    } else {
        // Минимальное выделение для пустой строки с корректным нулевым символом
        reserve(&str, 16);
        str.data[0] = '\0';
    }

    return str;
}