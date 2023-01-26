class Solution {
public:
    
    class compare {
        public:
            bool operator()(ListNode* a, ListNode* b) {
                return a->val > b->val;
            }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        
        int k = lists.size();
        
        for(int i = 0; i < k; i++) {
            if(lists[i] != NULL) {
                pq.push(lists[i]);
            }
        }
        
        ListNode* head = NULL;
        ListNode* tail = NULL;
        
        while(!pq.empty()) {
            
            ListNode* node = pq.top();
            pq.pop();
            
            if(node->next) {
                pq.push(node->next);
            }
            
            if(head == NULL) {
                head = node;
                tail = node;
            } else {
                tail->next = node;
                tail = node;
            }
            
        }
        
        return head;
        
    }
};