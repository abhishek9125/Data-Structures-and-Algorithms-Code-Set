class Solution {
  public:
  
    int countNodes(struct Node* root) {
        return root == NULL ? 0 : 1 + countNodes(root->left) + countNodes(root->right);
    }
    
    bool isCBT(struct Node* root, int i, int totalNodes) {
        
        if(root == NULL) {
            return true;
        }
        
        if(i >= totalNodes) {
            return false;
        }
        
        return isCBT(root->left, 2*i + 1, totalNodes) && isCBT(root->right, 2*i + 2, totalNodes);
        
    }
      
    bool maxOrder(struct Node* root) {
        
        if(root->left == NULL && root->right == NULL) {
            return true;
        }
        
        if(root->right == NULL) {
            if(root->left->data < root->data) {
                return true;
            }
        } else {
            bool left = maxOrder(root->left);
            bool right = maxOrder(root->right);
            
            if(root->data > root->left->data && root->data > root->right->data && left && right) {
                return true;
            }
        }
        
        return false;
    }
  
    bool isHeap(struct Node* root) {
        // code here
        int index = 0;
        int totalNodes = countNodes(root);
        
        if(isCBT(root, index, totalNodes) && maxOrder(root)) {
            return true;
        } 
        
        return false;
        
    }
};
