#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

// typedef struct Node {
//     int key;
//     struct Node* left;
//     struct Node* right;
// } Node;


Node* create_node(int key) {
  Node* new_node = malloc(sizeof(struct Node));

  new_node->key = key;
  new_node->left = NULL;
  new_node->right = NULL;

  return new_node;
}

Node* insert(Node* root, int key) {
   Node* new_node = create_node(key);

   if (root == NULL) {
    root = new_node;
    return root;
   }
   
   Node* current = root;
   int inserted = 0;

   while (!inserted) {
    if (current->key < key) {
      if (current->left != NULL) {
        current = current->left;
      } else {
        current->left = new_node;
        inserted = 1;
      }

    } else {
      if (current->right != NULL) {
        current = current->right;
      } else {
        current->right = new_node;
        inserted = 1;
      }
    }
   }

   return root;

}

Node* search(Node* root, int key) {
   Node* current = root;

   if (root == NULL) {
    return 0;
   }

   while (current != NULL) {
      if (current->key == key) {
        return current;
      }

      if (key < current->key) {
        current = current->left;
      } else {
        current = current->right;
      }
  }
  
  return 0;
}

static Node* find_min(Node* root) {
  if (root == NULL) {
    return 0;
  }

  Node* current = root;

  while(current->left != NULL) {
    current = current->left;
  }

  return current;
}

Node* delete(Node* root, int key) {
    if (root == NULL) {
        return NULL; 
    }

    // 1. Ищем узел для удаления
    if (key < root->key) {
        root->left = delete(root->left, key); // Перезаписываем левый указатель
    } else if (key > root->key) {
        root->right = delete(root->right, key); // Перезаписываем правый указатель
    } 
    // 2. Узел найден
    else {
        // Случай 1: У узла нет левого ребенка (или он вообще лист)
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp; // Возвращаем правого ребенка родителю
        } 
        // Случай 2: У узла нет правого ребенка
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp; // Возвращаем левого ребенка родителю
        }

        // Случай 3: У узла два ребенка
        // Находим минимальный элемент в ПРАВОМ поддереве
        Node* temp = find_min(root->right);

        // Копируем его ключ в текущий узел
        root->key = temp->key;

        // Рекурсивно удаляем дубликат ключа из правого поддерева
        root->right = delete(root->right, temp->key);
    }
    
    return root;
}

void inorder(Node* root) {
  if (root == NULL) {
    return;
  }

  Node* current = root;

  if (current->left != NULL) {
    inorder(current->left);
  }

  printf("%d ", current->key);

  if (current->right != NULL) {
    inorder(current->right);
  }
}

void free_tree(Node* root) {
  if (root == NULL) {
    return;
  }
  Node* current = root;

  if (current->left != NULL) {
    free_tree(current->left);
  }
  if (current->right != NULL) {
    free_tree(current->right);
  }
  free(root);
}