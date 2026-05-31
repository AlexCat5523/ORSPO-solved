#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// typedef struct Node {
//     int data;
//     struct Node* next;
//     struct Node* prev;
// } Node;


Node* create_node(int value) {
  Node* new_node = malloc(sizeof(struct Node)); // выделяем память на новый элемент массива

  // Заполняем элемент массива (следующий и предыдущий элементы пока что NULL, потому что пока что не знаем, на что им указывать)
  new_node->data = value;
  new_node->next = NULL;
  new_node->prev = NULL;

  return new_node;
}

void push_back(Node** head, int value) {
  Node* current = *head;  // это текущий элемент массива: изначально указывает на нулевой элемент

  Node* new_node = create_node(value);

  if (*head == NULL) {
    *head = new_node;
    return;
  }

  while (current->next != NULL) {
    current = current->next;  // переходим к следующему элементу массива
  }

  current->next = new_node;
  new_node->prev = current;
}

void insert_at(Node** head, int value, int index) {
  Node* new_node = create_node(value);

  Node* current = *head;
  if (index == 0) {
    current->prev = new_node;
    new_node->next = current;
    return;
  }

  for(int i = 0; i < index; i++) {
    if (i == index - 1) {
      new_node->next = current->next;
      new_node->prev = current;

      current->next = new_node;
    }
    current = current->next;

    current->next->prev = new_node;
  }
}

void delete_value(Node** head, int value) {
  Node* current = *head;

  while (current->data != value) {
    current = current->next;
  }

  current->prev->next = current->next;
  current->next->prev = current->prev;

  free(current);
}

Node* find(Node* head, int value) {
  Node* current = head;

  if (head == NULL) {
    return 0;
  }

  while(current->data != value) {
    current = current->next;
  }

  return current;
}

void free_list(Node* head) {
  Node* current = head;

  while (current != NULL) {
    current = current->next;
    free(head);
    head = current;
  }
}

void print_list(Node* head) {
  Node* current = head;

  printf("\n");
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
}

void print_list_reverse(Node* head) {
  Node* current = head;

  while (current->next != NULL) {
    current = current->next;
  }

  printf("\n");
  while (current->prev != NULL) {
    printf("%d ", current->data);
    current = current->prev;
  }
  printf("%d", current->data);
}