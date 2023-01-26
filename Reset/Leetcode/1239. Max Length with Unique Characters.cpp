class Solution
{
public:
    int solve(vector<string> &arr, int index, string temp)
    {

        if (index == arr.size())
        {

            int freq[26] = {0};
            for (int k = 0; k < temp.length(); k++)
            {

                if (freq[temp[k] - 'a'] == 1)
                {
                    return 0;
                }

                freq[temp[k] - 'a']++;
            }
            return temp.length();
        }

        int option1 = INT_MIN;
        int option2 = INT_MIN;

        if ((temp.length() + arr[index].length()) <= 26)
        {
            option1 = solve(arr, index + 1, temp + arr[index]);
        }

        option2 = solve(arr, index + 1, temp);

        return max(option1, option2);
    }

    int maxLength(vector<string> &arr)
    {
        return solve(arr, 0, "");
    }
};