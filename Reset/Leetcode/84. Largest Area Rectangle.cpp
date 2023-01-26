class Solution {

private:
    vector<int> nextSmallerElements(vector<int>& heights, int n) {
        
        stack<int> s;
        s.push(-1);
        vector<int> result(n);
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
        
        stack<int> s;
        s.push(-1);
        vector<int> result(n);
        for(int i = 0; i < n; i++) {
            while(s.top() != -1 && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            
            result[i] = s.top();
            s.push(i); 
        }
        return result;
    }
    
public:
    int largestRectangleArea(vector<int>& heights) {
    
        int n = heights.size();
        
        vector<int> next;
        next = nextSmallerElements(heights, n);
        
        vector<int> prev;
        prev = prevSmallerElements(heights, n);
        
        int area = 0;
        
        for(int i = 0; i < n; i++) {
            
            int l = heights[i];
            
            if(next[i] == -1) {
                next[i] = n;
            }
            
            int b = next[i] - prev[i] - 1;
            
            area = max(area, l*b);
        }
        
        return area;
    }
};