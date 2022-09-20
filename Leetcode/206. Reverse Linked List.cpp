class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* ptr = head;
        ListNode* current;
        ListNode* prev = NULL;
        
        while(ptr != NULL) {
            current = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = current;
        }
        
        head = prev;
        return head;
    }
};