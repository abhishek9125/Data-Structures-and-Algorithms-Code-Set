class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        
        while(temp != NULL) {
            
            ListNode* runner = temp->next;
            
            while(runner != NULL && runner->val == temp->val) runner = runner->next;
            
            temp->next = runner;
            temp = temp->next;
            
        }
        
        return head;
        
    }
};