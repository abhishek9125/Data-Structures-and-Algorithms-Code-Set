public:
long long findMinDiff(vector<long long> a, long long n, long long m)
{
    sort(a.begin(), a.end());

    long long i = 0;
    long long j = m - 1;
    long long mini = INT_MAX;

    while (j < a.size())
    {
        long long diff = a[j++] - a[i++];
        mini = min(mini, diff);
    }

    return mini;
}