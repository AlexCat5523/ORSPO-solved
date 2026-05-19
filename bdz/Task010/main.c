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