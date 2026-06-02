#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Структура заголовка POSIX ustar (размер ровно 512 байт)
struct tar_header {
    char name[100];     // Имя файла
    char mode[8];       // Права доступа (восьмеричные)
    char uid[8];        // ID пользователя (восьмеричный)
    char gid[8];        // ID группы (восьмеричный)
    char size[12];      // Размер файла в байтах (восьмеричный, с '\0' на конце)
    char mtime[12];     // Время модификации (восьмеричное)
    char chksum[8];     // Контрольная сумма заголовка
    char typeflag;      // Тип файла ('0' или '\0' для обычного файла)
    char linkname[100]; // Имя связанного файла
    char magic[6];      // Магическое число "ustar"
    char version[2];    // Версия "00"
    char uname[32];     // Имя пользователя
    char gname[32];     // Имя группы
    char devmajor[8];   // Старший номер устройства
    char devminor[8];   // Младший номер устройства
    char prefix[155];   // Префикс пути
    char padding[12];   // Дополнение до 512 байт
};

// Функция расчета контрольной суммы заголовка
void calculate_checksum(struct tar_header *header) {
    // Согласно стандарту, при расчете контрольной суммы само поле chksum заполняется пробелами
    memset(header->chksum, ' ', 8);
    
    unsigned int sum = 0;
    unsigned char *bytes = (unsigned char *)header;
    for (int i = 0; i < 512; i++) {
        sum += bytes[i];
    }
    
    // Запись суммы в виде 6-значного восьмеричного числа с завершающим нулем и пробелом
    sprintf(header->chksum, "%06o", sum);
}


void add_file_to_tar(FILE *tar_out, const char *filename) {
    FILE *in = fopen(filename, "rb");

    fseek(in, 0, SEEK_END);
    long filesize = ftell(in);
    fseek(in, 0, SEEK_SET);


    struct tar_header header;
    memset(&header, 0, sizeof(struct tar_header));

    strncpy(header.name, filename, 100);
    sprintf(header.mode, "%07o", 0644);
    sprintf(header.uid, "%07o", 1000);
    sprintf(header.gid, "%07o", 1000);
    sprintf(header.size, "%011lo", filesize); 
    sprintf(header.mtime, "%011lo", 1717315200L); 
    header.typeflag = '0';
    
    memcpy(header.magic, "ustar ", 6);
    memcpy(header.version, " 0", 2);
    strncpy(header.uname, "user", 32);
    strncpy(header.gname, "user", 32);


    calculate_checksum(&header);


    fwrite(&header, sizeof(struct tar_header), 1, tar_out);


    char buffer[512];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, 512, in)) > 0) {
        if (bytes_read < 512) {
            memset(buffer + bytes_read, 0, 512 - bytes_read);
        }
        fwrite(buffer, 512, 1, tar_out);
    }

    fclose(in);
}

int main(int argc, char *argv[]) {
    // Входные параметры: argv[1] - имя создаваемого архива, остальные аргументы - файлы для упаковки
    FILE *tar_out = fopen(argv[1], "wb");

    // Последовательно добавляем каждый переданный файл
    for (int i = 2; i < argc; i++) {
        add_file_to_tar(tar_out, argv[i]);
    }

    // Запись маркера конца архива (EOF) — два блока по 512 байт, заполненных нулями
    char end_marker[1024];
    memset(end_marker, 0, 1024);
    fwrite(end_marker, 1, 1024, tar_out);

    fclose(tar_out);
    return 0;
}