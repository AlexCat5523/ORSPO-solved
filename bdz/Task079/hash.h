#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 50000 

typedef struct Ht_item {
    char* key;
    char* value;
    struct Ht_item* next;
} Ht_item;


typedef struct HashTable {
    Ht_item* items[CAPACITY]; 
} HashTable;


unsigned long hash_function(char* str) {
    unsigned long i = 0;
    for (int j = 0; str[j]; j++)
        i += str[j];
    return i % CAPACITY;
}


static int custom_strcmp(const char* s1, const char* s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(unsigned char*)s1 - *(unsigned char*)s2;
}

HashTable* create_table() {
    HashTable* table = (HashTable*)malloc(sizeof(HashTable));
    if (table == NULL) return NULL;
    
    for (int i = 0; i < CAPACITY; i++) {
        table->items[i] = NULL;
    }
    return table;
}


void insert(HashTable* table, char* key, char* value) {
    if (table == NULL || key == NULL) return;

    unsigned long index = hash_function(key);
    Ht_item* current = table->items[index];


    while (current != NULL) {
        if (custom_strcmp(current->key, key) == 0) {
            current->value = value; // Обновляем значение
            return;
        }
        current = current->next;
    }

    Ht_item* new_item = (Ht_item*)malloc(sizeof(Ht_item));
    if (new_item == NULL) return;
    
    new_item->key = key;
    new_item->value = value;

    new_item->next = table->items[index];
    table->items[index] = new_item;
}


char* search(HashTable* table, char* key) {
    if (table == NULL || key == NULL) return NULL;

    unsigned long index = hash_function(key);
    Ht_item* current = table->items[index];

    while (current != NULL) {
        if (custom_strcmp(current->key, key) == 0) {
            return current->value; // Ключ найден
        }
        current = current->next;
    }
    
    return NULL; 
}

void delete(HashTable* table, char* key) {
    if (table == NULL || key == NULL) return;

    unsigned long index = hash_function(key);
    Ht_item* current = table->items[index];
    Ht_item* prev = NULL;


    while (current != NULL) {
        if (custom_strcmp(current->key, key) == 0) {
            // Если удаляемый элемент — первый в списке
            if (prev == NULL) {
                table->items[index] = current->next;
            } else {
                prev->next = current->next;
            }
            free(current); 
            return;
        }
        prev = current;
        current = current->next;
    }
}


void free_table(HashTable* table) {
    if (table == NULL) return;
    for (int i = 0; i < CAPACITY; i++) {
        Ht_item* current = table->items[i];
        while (current != NULL) {
            Ht_item* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(table);
}