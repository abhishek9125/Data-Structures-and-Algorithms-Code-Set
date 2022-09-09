    void heapify(vector<int> &nums, int i, int n) {
        
        int largest = i;
        
        int left = 2*i + 1;
        int right = 2*i + 2;
        
        if(left < n && nums[left] > nums[largest]) {
            largest = left;
        } 
        
        if (right < n && nums[right] > nums[largest]) {
            largest = right;
        }
        
        if(largest != i) {
            swap(nums[largest], nums[i]);
            heapify(nums, largest, n);
        }
        
        return;
        
    }
    
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        vector<int> result;
        for(auto i : a) {
            result.push_back(i);
        }
        for(auto i : b) {
            result.push_back(i);
        }
        
        int finalSize = n + m;
        
        for(int i = finalSize/2 ; i >= 0; i--) {
            heapify(result, i, finalSize);

        }

        return result;
        
    }