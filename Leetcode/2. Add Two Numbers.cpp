class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        if(l1 == NULL) {
            return l2;
        }
        
        if(l2 == NULL) {
            return l1;
        }
        
        ListNode* result = new ListNode();
        ListNode* temp = result;
        
        int carry = 0;
        
        while(l1 || l2 || carry) {
            
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            
            temp->next = new ListNode(sum%10);
            carry = sum / 10;
            
            temp = temp->next;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;     
        }
        
        return result->next;
    }
};