#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct __attribute__((packed)) tar_header {
    char name[100];
    char unused1[24];
    char size[12];
    char unused2[12];
    char chksum[8];
    char typeFlag;
    char unused3[100];
    char magic[6];
    char unused4[250];
};

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

void add_file_to_tar(FILE * tar_out, const char *filename) {
    FILE * fp = fopen(filename, "rb");

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    struct tar_header header;
    memset(&header, 0, sizeof(struct tar_header));

    strcpy(header.name, filename);
    sprintf(header.size, "%011lo", size);

    header.typeFlag = '0';
    memcpy(header.magic, "ustar ", 6);

    calculate_checksum(&header);

    fwrite(&header, sizeof(struct tar_header), 1, tar_out);


    char buffer[512];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, 512, fp)) > 0) {
        if (bytes_read < 512) {
            memset(buffer + bytes_read, 0, 512 - bytes_read);
        }
        fwrite(buffer, 512, 1, tar_out);
    }

    fclose(fp);
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