class Solution {
public:
    
    struct compare {
        bool operator()(pair<int,string> p1,pair<int,string> p2){
            if(p1.first == p2.first){
                return p1.second < p2.second;
            }else{
                return p1.first > p2.first;
            }    
        };   
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> result;
        unordered_map<string, int> freq;
        priority_queue<pair<int,string>,vector<pair<int,string>>,compare> pq; 
        
        for(auto i: words) {
            freq[i]++;
        }
        
        for(auto i : freq) {
            pq.push(make_pair(i.second, i.first));
            if(pq.size() > k) {
                pq.pop();
            }
        }

        int i = 0;
        
        while(i < k) {
            result.insert(result.begin(), pq.top().second);
            pq.pop();
            i++;
        }
        return result;
    }
};