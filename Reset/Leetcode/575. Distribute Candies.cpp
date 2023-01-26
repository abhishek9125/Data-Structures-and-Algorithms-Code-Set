class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        
        unordered_map<int, bool> m;
        
        for(auto i : candyType) {
            m[i] = true;
        }
        
        return min(m.size(), candyType.size()/2);
        
    }
};