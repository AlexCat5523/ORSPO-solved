int floyds_cycle(Node* head) {
    Node* tutel = head;
    Node* hare = head;

    if (head == NULL || head->next == NULL) {
        return 0;
    }

    while (hare && hare->next) {
        tutel = tutel->next;
        hare = hare->next->next;

        if (tutel == hare) {
            return 1;
        }
    }
    
    return 0;
}