#include <stdio.h>
#include <string.h>


int main() {
    char *filename = "data.txt";
    char string[256];

    char c;
    printf("Введите строку: ");
    scanf("%s", string);

    FILE * fp = fopen(filename, "r");

    int cur_row = 0;
    int row = -1;
    int ind = -1;

    char msg[256];
    int i = 0;
    if (fp) {
        char *ptr;
        while ((c = getc(fp)) != EOF) {
            if (c == '\n' || i > 255) {
                msg[i] = '\0';
                ptr = strstr(msg, string);

                if (ptr != 0) {
                    row = cur_row;
                    ind = ptr - msg;
                    break;
                }
                cur_row++;
                i = 0;
                continue;
            }
            msg[i] = c;
            i++;
        }
    }

    if (i > 0 && row == -1) {
        msg[i] = '\0';
        char *ptr = strstr(msg, string);
        if (ptr != NULL) {
            row = cur_row;
            ind = ptr - msg;
        }
    }

    fclose(fp);
    printf("%d %d\n", row, ind);
}