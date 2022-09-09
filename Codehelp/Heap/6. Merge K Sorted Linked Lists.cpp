class compare {
    public:
        bool operator()(Node<int>* a, Node<int>* b) {
            return a->data > b->data;
        }
};

Node<int>* mergeKLists(vector<Node<int>*> &listArray)
{
    // Write your code here.
    priority_queue<Node<int>*, vector<Node<int>*>, compare> pq;
    int k = listArray.size();
    
    if(k == 0) return NULL;
    
    for(int i = 0; i < k; i++) {
        if(listArray[i] != NULL) {
            pq.push(listArray[i]);        
        }
    }
    
    Node<int>* head = NULL;
    Node<int>* tail = NULL;
    
    while(!pq.empty()) {
        Node<int>* top = pq.top();
        pq.pop();
        
        if(top->next != NULL) {
            pq.push(top->next);
        }
        
        if(head == NULL) {
            head = top;
            tail = top;
        } else {
            tail->next = top;
            tail = top;
        }
    }
    
    return head;
    
}