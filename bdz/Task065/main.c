#include <stdio.h>
#include <string.h>


char *my_strstr(const char *str, const char *substr) {
    if (*str == '\0') {
        return (char*)str;
    }

    for (const char* word = str; *word != '\0'; word++) {
        const char *str_ptr = word;
        const char *substr_ptr = substr;

        while (*str_ptr != '\0' && *substr_ptr != '\0' && *str_ptr == *substr_ptr) {
            str_ptr++;
            substr_ptr++;
        }

        if (*substr_ptr == '\0') {
            return (char*)word;
        }
    }

    return 0;
}


int main()
{
    char text[256];
    printf("Введите фразу: ");
    fgets(text, sizeof(text), stdin);

    char *pos = strstr(text, "hello");
    char* my_pos = my_strstr(text, "hello");

    if (pos != NULL)
        printf("Found at index: %ld\n", pos - text);
    else
        printf("Substring not found\n");

    if (my_pos != NULL)
        printf("My_strstr: Found at index: %ld\n", my_pos - text);
    else
        printf("My_strtr: Substring not found\n");

    return 0;
}