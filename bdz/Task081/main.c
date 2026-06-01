#include <stdio.h>
  
int main(void)
{
    // символ для считывания
    char c;
    // файл для чтения
    char * filename = "data.txt";
 
    FILE * fp= fopen(filename, "r");
    if(fp)
    {
        // считываем посимвольно из файла
        while((c = getc(fp)) != EOF)
        {
            printf("%c", c);
        }
        fclose(fp);
    }

    char message[] = "Hello Kusya!";
    int n = sizeof(message) / sizeof(message[0]);
    fp = fopen(filename, "w");
    if (fp) {
        for (int i = 0; i < n; i++) {
            putc(message[i], fp);
        }
        fclose(fp);
    }
}