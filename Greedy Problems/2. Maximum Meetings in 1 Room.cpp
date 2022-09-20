class Solution{
public:
    static bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
        
        if(a.second.second == b.second.second) {
            return a.first < b.first;
        }
        
        return a.second.second < b.second.second;    
    }
    
    vector<int> maxMeetings(int n,vector<int> &start,vector<int> &end){
        
        vector<pair<int, pair<int, int>>> v;
        vector<int> result;
        
        for(int i = 0; i < n; i++) {
            pair<int, pair<int, int>> p = make_pair(i+1, make_pair(start[i], end[i]));
            v.push_back(p);
        }
        
        sort(v.begin(), v.end(), cmp);

        int ansEnd = v[0].second.second;
        result.push_back(v[0].first);
        for(int i = 1; i < n; i++) {
            if(v[i].second.first > ansEnd) {
                ansEnd = v[i].second.second;
                result.push_back(v[i].first);
            }
        }
        
        sort(result.begin(), result.end());
        
        return result;
    }
};