class Solution
{
public:
    static bool cmp(pair<double, Item> a, pair<double, Item> b)
    {
        return a.first > b.first;
    }

    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector<pair<double, Item>> v;

        for (int i = 0; i < n; i++)
        {
            v.push_back(make_pair((1.0 * arr[i].value / arr[i].weight), arr[i]));
        }

        sort(v.begin(), v.end(), cmp);

        double totalValue = 0;

        for (int i = 0; i < n; i++)
        {

            if (v[i].second.weight > W)
            {
                totalValue += W * v[i].first;
                W = 0;
                break;
            }
            else
            {
                totalValue += v[i].second.value;
                W = W - v[i].second.weight;
            }
        }

        return totalValue;
    }
};
