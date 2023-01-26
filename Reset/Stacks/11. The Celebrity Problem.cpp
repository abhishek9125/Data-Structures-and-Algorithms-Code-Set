class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> s;
        
        for(int i = 0; i < n; i++) {
            s.push(i);
        }
        
        while(s.size() > 1) {
            
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            
            if(M[a][b]) {
                s.push(b);
            } else if(M[b][a]){
                s.push(a);
            }
            
        }
        
        int candidate = s.top();
        
        bool rowCheck = false;
        int rowCount = 0;
        
        for(int i = 0; i < n; i++) {
            if(M[i][candidate] == 1) {
                rowCount++;
            }
        }
        
        if(rowCount == n - 1) {
            rowCheck = true;
        }
        
        bool colCheck = false;
        int colCount = 0;
        
        for(int i = 0; i < n; i++) {
            if(M[candidate][i] == 0) {
                colCount++;
            }
        }
        
        if(colCount == n) {
            colCheck = true;
        }
        
        if(rowCheck && colCheck) {
            return candidate;
        }
        
        return -1;
    }
};