# Task010 — Кроссплатформенность 🔍

## Предопределенные макросы для определения ОС

|Операционная система | Макрос|
| :--- | :--- | 
| `Windows (32-bit)` | `_WIN32` |
| `Windows (64-bit)` |  `_WIN64`|
| `Linux` | `__linux__` |
| `macOS` |  `__APPLE__` |
| `Unix` | `__unix__` |
| `FreeBSD` | `__FreeBSD__` |

---

## Задание 

* Скомпилируйте и запустите программу в ОС Linux (виртуальная машина, WSL и т.д.)

* Скомпилируйте и запустите программу в ОС Windows (можно использовать любой компилятор: MinGW, MSVC, Cygwin).

* Сравните результаты выполнения на разных ОС.

* Используя дополнительную литературу, изучите, какие еще существуют встроенные макросы для определения:

    * Компилятора (GCC, Clang, MSVC)

    * Версии компилятора

    * Архитектуры процессора (x86, x86_64, ARM)

    * Стандарта языка (C11, C17, C23)

* Модифицируйте программу так, чтобы она выводила:

    * Название ОС

    * Название компилятора

    * Архитектуру процессора


# Решение
Для компиляции и запуска нужно:
```bash
gcc main.c -o main
./main
```

* На Linux выдаст *Running on Linux/Unix*, на Windows выдаст *Running on Windows*

* Доп.литературу ищите сами (просто забейте в гугл)

* Модифицированная программа (скопируйте и полностью заменить `main.c`):
  
```c
#include <stdio.h>

int main() {
    // 1. Определение операционной системы
    printf("OS: ");
    #if defined(_WIN32) || defined(_WIN64)
        printf("Windows\n");
    #else
        printf("Linux\n");
    #endif

        // 2. Определение компилятора
        printf("Compiler: ");
    #if defined(__clang__)
        printf("Clang (%d.%d.%d)\n", __clang_major__, __clang_minor__, __clang_patchlevel__);
    #elif defined(__GNUC__)
        printf("GCC (%d.%d.%d)\n", __GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__);
    #else
        printf("MSVC (Internal version: %d)\n", _MSC_VER);
    #endif

        // 3. Определение архитектуры процессора
        printf("Architecture: ");
    #if defined(_M_X64)
        printf("x86_64 (64-bit)\n");
    #elif defined(_M_IX86)
        printf("x86 (32-bit)\n");
    #elif defined(_M_ARM64)
        printf("ARM64 (AArch64)\n");
    #else
        printf("ARM (32-bit)\n");
    #endif
    return 0;
}
```

После этого можно опять скомпиллировать и запустить программу и убедиться в работе программы