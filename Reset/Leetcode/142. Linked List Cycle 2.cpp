/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    ListNode* detectLoop(ListNode* head) {
        
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast != NULL) {
            
            fast = fast->next;
            
            if(fast != NULL) {
                fast = fast->next;
            }
            
            slow = slow->next;
            
            if(fast == slow) {
                return fast;
            }
            
            
        }
        
        return NULL;
        
        
    }
    
    ListNode *detectCycle(ListNode *head) {
        
        if(head == NULL) {
            return NULL;
        }
        
        ListNode* intersection = detectLoop(head);
        
        if(intersection == NULL) {
            return NULL;
        }
        
        ListNode* slow = head;
        
        while(slow != intersection) {
            slow = slow->next;
            intersection = intersection->next;
        }

        ListNode* runner = slow;

        while(runner->next != slow) {
            runner = runner->next;
        }
        
        runner->next = NULL;

        return slow;
        
    }
};



