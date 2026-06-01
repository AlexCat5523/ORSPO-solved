#include <stdio.h>
#include <string.h>


int is_delimiter(const char c, const char * delim) {
    while (*delim != '\0') {
        if (*delim == c) {
            return 1;
        } else {
            delim++;
        }
    }
    return 0;
}

char * my_strtok( char * string, const char * delim ) {
    static char* word = NULL;       // static позволяет сохранять для данной переменной её значение в последующих вызовах функции

    if (string != 0) {
        word = string;
    }

    while (*word != '\0' && is_delimiter(*word, delim)) {
        word++;
    }

    if (*word == 0) {
        return 0;
    }

    char* start = word;

    while (*word != '\0') {
        if (is_delimiter(*word, delim)) {
            // из-за добавления '\0' в конец слова, мы для start изолируем наше слово. т.е. представим строку "Hello World" с разделителем в виде пробела,
            // в таком случае start = "Hello World" (31 строчка), однако при нахождении пробела программа заменяет его на '\0' - символ окончания строки. Поэтому когда мы вернем
            // start, функция дойдет до этого символа окончания строки и не напечатает ничего, что идет следом за ней.
            *word = '\0';
            word++;
            return start;
        }
        word++;
    }
    return start;
}
 
int main ()
{
    char myStr[] = "Richard of Yourk Gave Battle in Vain";
    char myStr2[] = "Richard of Yourk Gave Battle in Vain";
    char * myPtr = strtok(myStr, " ");
    char * myPtr2 = my_strtok(myStr2, " ");

    while(myPtr != NULL) {
        printf("%s\n", myPtr);
        myPtr = strtok(NULL, " ");
    }
    printf("\nMyStrtok:\n");
    while(myPtr2 != NULL) {
        printf("%s\n", myPtr2);
        myPtr2 = my_strtok(NULL, " ");
    }
}