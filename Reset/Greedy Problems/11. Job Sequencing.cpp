/*
struct Job
{
    int id;	 // Job Id
    int dead; // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
*/

class Solution
{
public:
    // Function to find the maximum profit and the number of jobs done.

    static bool cmp(Job a, Job b)
    {
        return a.profit > b.profit;
    }

    vector<int> JobScheduling(Job arr[], int n)
    {

        sort(arr, arr + n, cmp);

        int count = 0;
        int maxProfit = 0;
        int maxDeadline = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            maxDeadline = max(maxDeadline, arr[i].dead);
        }

        vector<int> schedule(maxDeadline + 1, -1);

        for (int i = 0; i < n; i++)
        {

            int currentProfit = arr[i].profit;
            int currentJobId = arr[i].id;
            int currentDeadline = arr[i].dead;

            for (int j = currentDeadline; j > 0; j--)
            {
                if (schedule[j] == -1)
                {
                    count++;
                    maxProfit += currentProfit;
                    schedule[j] = currentJobId;
                    break;
                }
            }
        }

        return {count, maxProfit};
    }
};