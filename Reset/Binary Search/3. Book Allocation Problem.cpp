
bool isPossible(vector<int>& time, int n, int m, int mid) {
    int studentCount = 1;
    int pageSum = 0;
    
    for(int i = 0; i < n; i++) {
        if(pageSum + time[i] <= mid) {
            pageSum += time[i];
        } else {
            studentCount++;
            pageSum = time[i];
            
            if(studentCount > m || time[i] > mid) {
                return false;
            }
        }
    }
    return true;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time) {
    long long start = 0;
    long long end = 0;
    for(auto i : time) {
        end += i;
    }
    
    long long ans = -1;
    
    while(start <= end) {
        long long mid = start + (end - start) / 2;
        
        if(isPossible(time, m, n, mid)) {
            ans = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    
    return ans;
    
}