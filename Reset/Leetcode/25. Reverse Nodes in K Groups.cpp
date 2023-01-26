/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head == NULL) {
            return NULL;
        }
        
        ListNode* temp = head;
        int count = 0;

        while(temp != NULL) {
            temp = temp->next;
            count++;
        }
     
        if(count < k) {
            return head;
        }
        
        count = 0;
        ListNode* prev = NULL;
        ListNode* current;
        ListNode* ptr = head;
        
        while(ptr != NULL && count < k) {
            current = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = current;
            count++;
        }

        if(current != NULL) {
            head->next = reverseKGroup(current, k);
        }
        
        return prev;
        
    }
};