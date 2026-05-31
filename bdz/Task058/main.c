// Списки уже отсортированы по возрастанию

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    ListNode* cur1 = list1;
    ListNode* cur2 = list2;

    ListNode dummy;         // Список, к которому мы будем цеплять значения из list1 и list2
    ListNode* res = &dummy; // указатель на этот список
    dummy.next = NULL;

    // Если значение из list1 меньше, чем из list2, то прибавляем значение из list1 и наоборот
    while (cur1 != NULL && cur2 != NULL) {
        if (cur1->val <= cur2->val) {
            res->next = cur1;
            cur1 = cur1->next;
        } else {
            res->next = cur2;
            cur2 = cur2->next;
        }
        res = res->next;
    }

    // Добавляем остаток нужного списка( если он есть)
    if (cur1 != NULL) {
        res->next = cur2;
    } else {
        res->next = cur2;
    }
    return dummy.next;  // Возвращаем next, потому что ListNode*
}