class Solution {
public:
    
    vector<int> nextSmallerElements(vector<int>& heights, int n) {
        
        vector<int> result(n);
        stack<int> s;
        
        s.push(-1);
        
        for(int i = n - 1; i >= 0; i--) {
            
            while(s.top() != -1 && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            
            result[i] = s.top();
            s.push(i);
        }
        
        return result;
    }
    
    vector<int> prevSmallerElements(vector<int>& heights, int n) {
        
        vector<int> result(n);
        stack<int> s;
        
        s.push(-1);
        
        for(int i = 0; i < n; i++) {
            
            while(s.top() != -1 && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            
            result[i] = s.top();
            s.push(i);
        }
        
        return result;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        
        vector<int> next;
        next = nextSmallerElements(heights, n);
        
        vector<int> prev;
        prev = prevSmallerElements(heights, n);
        
        int area = 0;
        
        for(int i = 0; i < n; i++) {
            
            int length = heights[i];
            
            if(next[i] == -1) {
                next[i] = n;
            }
            
            int breadth = next[i] - prev[i] - 1;
            
            area = max(area, length*breadth);
        }
        
        return  area;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>> nums;
        
        for(int i = 0; i < n; i++) {
            vector<int> temp;
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == '1') {
                    temp.push_back(1);
                } else {
                    temp.push_back(0);
                }
            }
            nums.push_back(temp);
        }
        

        
        int area = largestRectangleArea(nums[0]);
        
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(nums[i][j] != 0) {
                    nums[i][j] = nums[i][j] + nums[i-1][j];
                } else {
                    nums[i][j] = 0;
                }
            }
            
            area = max(area, largestRectangleArea(nums[i]));
            
        }
        
        return area;
    }
};