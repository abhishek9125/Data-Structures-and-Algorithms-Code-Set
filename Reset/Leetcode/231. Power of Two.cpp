class Solution {
public:
    bool isPowerOfTwo(int n) {
        int ans = 1;
        
        for(int i = 0; i <= 30; i++) {
            if(ans == n) {
                return true;
            }
            
            if(ans < INT_MAX/2) {
                ans = ans*2;            
            }
            
        }
        
        return false;
        
    }
};

class Solution {
public:
    bool isPowerOfTwo(int n) {
      if(n < 1) {
            return false;
        }
        if(n == 1) {
            return true;
        }
        
        if(n%2 == 0) {
            return isPowerOfTwo(n/2);
        } else {
            return false;
        }  
    }
};