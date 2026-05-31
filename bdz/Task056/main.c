Node* turn(Node* head) {
    Node* reversed_head = NULL;     // Будущий развернутый список
    Node* current = head;           // Нынешний элемент

    // Определяем длину списка
    int len = 0;
    while (current != NULL) {
        len++;
        current = current->next;
    }
    int data[len];
    current = head;

    // Заполняем массив элементами в обратном порядке
    for (int i = 0; i < len; i++) {
        data[len - i - 1] = current->data;
        current = current->next;
    }
    // Добавляем в односвязный список элементы из нашего массива (внутри массива они уже в обратном порядке)
    for (int i = 0; i < len; i++) {
        push_back(&reversed_head, data[i]);
    }

    return reversed_head;
}