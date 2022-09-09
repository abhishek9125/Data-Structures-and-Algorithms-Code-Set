class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        
        long long cost = 0;
        
        for(long long i = 0; i < n; i++) {
            pq.push(arr[i]);
        }
        
        while(pq.size() > 1) {
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();
            
            long long sum = a + b;
            cost += sum;
            
            pq.push(sum);
        }
        
        return cost;
        
    }
};