#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

// typedef struct Node {
//     int key;
//     int height;
//     struct Node *left;
//     struct Node *right;
// } Node;

int height(Node *n) {
    return n->height;
}

// Возвращает максимальное из двух целых чисел
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Создание нового узла
Node* create_node(int key) {
    Node* new_node = (Node*)malloc(sizeof(Node));

    new_node->key = key;
    new_node->height = 0;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Малое правое вращение вокруг узла y
Node* right_rotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Выполнение вращения
    x->right = y;
    y->left = T2;

    // Пересчет высот (порядок важен: сначала для y, затем для x)
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Возврат нового корня поддерева
    return x;
}

// Малое левое вращение вокруг узла x
Node* left_rotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Выполнение вращения
    y->left = x;
    x->right = T2;

    // Пересчет высот (сначала для x, затем для y)
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Возврат нового корня поддерева
    return y;
}

// Получение фактора баланса узла n
int get_balance(Node* n) {
    if (n == NULL) {
        return 0;
    }
    return height(n->right) - height(n->left);
}

// Поиск узла по ключу
Node* search(Node* root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }
    
    if (key < root->key) {
        return search(root->left, key);
    }
    return search(root->right, key);
}

// Вставка ключа в дерево с последующей балансировкой
Node* insert(Node* node, int key) {
    // 1. Стандартная вставка в двоичное дерево поиска
    if (node == NULL) {
        return create_node(key);
    }

    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    } else {
        return node; // Дубликаты ключей не допускаются
    }

    // 2. Обновление высоты текущего узла
    node->height = 1 + max(height(node->left), height(node->right));

    // 3. Получение фактора баланса для проверки необходимости вращений
    int balance = get_balance(node);

    // Если узел разбалансирован, рассматриваются 4 случая:

    // Левый-Левый случай (LL) -> требуется правое вращение
    if (balance < -1 && key < node->left->key) {
        return right_rotate(node);
    }

    // Правый-Правый случай (RR) -> требуется левое вращение
    if (balance > 1 && key > node->right->key) {
        return left_rotate(node);
    }

    // Левый-Правый случай (LR) -> требуется большое правое вращение
    if (balance < -1 && key > node->left->key) {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }

    // Правый-Левый случай (RL) -> требуется большое левое вращение
    if (balance > 1 && key < node->right->key) {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }

    return node;
}

// Поиск узла с минимальным ключом в поддереве (самый левый узел)
static Node* find_min(Node* node) {
    Node* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Удаление узла по ключу с последующей балансировкой
Node* delete(Node* root, int key) {
    // 1. Стандартное удаление из двоичного дерева поиска
    if (root == NULL) {
        return root;
    }

    if (key < root->key) {
        root->left = delete(root->left, key);
    } else if (key > root->key) {
        root->right = delete(root->right, key);
    } else {
        // Узел с одним дочерним элементом или без них
        if ((root->left == NULL) || (root->right == NULL)) {
            Node *temp = root->left ? root->left : root->right;

            if (temp == NULL) { // Случай без дочерних узлов
                temp = root;
                root = NULL;
            } else { // Случай с одним дочерним узлом
                *root = *temp; // Копирование содержимого
            }
            free(temp);
        } else {
            // Узел с двумя дочерними элементами: получаем инфиксного преемника
            Node* temp = find_min(root->right);

            // Копируем ключ преемника в данный узел
            root->key = temp->key;

            // Удаляем преемника
            root->right = delete(root->right, temp->key);
        }
    }

    // Если дерево состояло только из одного узла
    if (root == NULL) {
        return root;
    }

    // 2. Обновление высоты текущего узла
    root->height = 1 + max(height(root->left), height(root->right));

    // 3. Получение фактора баланса
    int balance = get_balance(root);

    // Проверка баланса и выполнение вращений

    // Левый-Левый случай (LL)
    if (balance < -1 && get_balance(root->left) <= 0) {
        return right_rotate(root);
    }

    // Левый-Правый случай (LR)
    if (balance < -1 && get_balance(root->left) > 0) {
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }

    // Правый-Правый случай (RR)
    if (balance > 1 && get_balance(root->right) >= 0) {
        return left_rotate(root);
    }

    // Правый-Левый случай (RL)
    if (balance > 1 && get_balance(root->right) < 0) {
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }

    return root;
}

// Симметричный обход дерева (In-order traversal) для вывода элементов
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d (h=%d) ", root->key, height(root));
        inorder(root->right);
    }
}

// Рекурсивное освобождение памяти, занимаемой деревом
void free_tree(Node* root) {
    if (root != NULL) {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}