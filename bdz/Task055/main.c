int is_symmetric(Node *head) {
    Node* current = head;

    // Узнаем длину списка
    int count = 0;
    while (current != NULL) {
        count++;
        current = current->next;
    }

    int data[count];
    current = head;
    // Создаем массив, в котором в обратном порядке лежат числа из списка
    for (int i = 0; i < count; i++) {
        data[count - i - 1] = current->data;
        current = current->next;
    }

    current = head;
    // Сравниваем
    for (int i = 0; i < count; i++) {
        if (current->data == data[i]) {
            current = current->next;
        } else {
            return 0;
        }
    }
    
    return 1;
}