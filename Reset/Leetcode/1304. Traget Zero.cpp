class Solution {
public:
    vector<int> sumZero(int n) {
        
        int elementCount = n / 2;
        
        vector<int> v;
        
        for(int i = elementCount; i > 0; i--) {
            v.push_back(i*-1);
            v.push_back(i);
        }
        
        if(n % 2 == 1) v.push_back(0);
     
        return v;
    }
};