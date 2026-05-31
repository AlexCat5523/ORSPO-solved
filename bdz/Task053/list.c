#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// typedef struct Node {
//     int data;
//     struct Node* next;
// } Node;

// Создание нового узла
Node* create_node(int value) {
   struct Node *new_node = malloc(sizeof(struct Node));
   
   new_node->data = value;
   new_node->next = NULL;

   return new_node;
}

// Добавление в конец
void push_back(Node** head, int value) {
   Node* new_node = create_node(value);

   Node* current = *head;
   if (*head == NULL) {
      *head = new_node;
      return;
   }
   while (current->next != NULL) {
      current = current->next;
   }
   current->next = new_node;
}

// Вставка по индексу (0 — в начало)
void insert_at(Node** head, int value, int index) {
   Node* new_node = create_node(value);

   int i = 0;
   Node* current = *head;

   if (index == 0) {
      new_node->next = *head;
      *head = new_node;
      return;
   }

   while (i != index) {
      current = current->next;
      i++;
   }

   // Выполнится на (i-1)-ом индексе
   Node* next_val = current->next;

   current->next = new_node;
   new_node->next = next_val;
}

// Удаление по значению (первое вхождение)
void delete_value(Node** head, int value) {
   Node* current = *head;
   Node* next_val = current->next;

   while (next_val != NULL) {
      if (next_val->data == value) {
         current->next = next_val->next;
         free(next_val);
         return;
      }
      current = current->next;
      next_val = next_val->next;
   }
}

// Поиск элемента
Node* find(Node* head, int value) {
  Node* current = head;

  while (current->data != value) {
   current = current->next;
  } 

  return current;
}

// Вывод списка
void print_list(Node* head) {
  Node* current = head;

  printf("\n");
   while (current != NULL) {
      printf("%d ", current->data);
      current = current->next;
   }
}

// Освобождение памяти
void free_list(Node* head) {
   while (head != NULL) {
      Node* current = head;
      head = head->next;
      free(current);
   }
}