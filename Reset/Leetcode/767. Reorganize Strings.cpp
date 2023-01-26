class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int, char>> pq;
        unordered_map<char, int> freq;
        string result = "";
        
        for(auto i: s) {
            freq[i]++;
        } 
        
        for(auto i : freq) {
            pq.push(make_pair(i.second, i.first));
        }
        
        while(!pq.empty()) {
            
            if(pq.size() == 1 && pq.top().first > 1) {
                return "";
            }
            
            pair<int, char> p = pq.top();
            pq.pop();
            result += p.second;
            if(!pq.empty()) {
                pair<int, char> p2 = pq.top();
                pq.pop();
                result += p2.second;
                if(p2.first > 1) {                    
                    pq.push(make_pair(p2.first-1, p2.second));
                }
            }
            if(p.first > 1) {
                pq.push(make_pair(p.first-1, p.second));
            }
            

            
        }
        
        return result;
    }
};