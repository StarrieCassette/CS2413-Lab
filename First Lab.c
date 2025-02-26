//Emmanuel Matamoros R11854157

//203. Remove Linked List Elements
struct ListNode* removeElements(struct ListNode* head, int val) {
        while (head != NULL && head->val == val){
            head = head->next;
        }
    struct ListNode* current_node = head;
    while (current_node != NULL && current_node->next != NULL){
        if (current_node->next->val == val){
            current_node->next = current_node->next->next;
        }else{
            current_node = current_node->next;
        }
    }
    return head;
}

//206. Reverse Linked List
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* current_node = head;
    struct ListNode* prev = NULL;
    while (head != NULL){
        struct ListNode* next_node = head->next;
        head->next = prev;
        prev = head;
        head = next_node;
    }
    return prev;
}
