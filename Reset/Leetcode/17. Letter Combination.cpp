class Solution {
public:
    

    void solve(string digits, string output, int index, vector<string>& result) {
        string keypad[] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

        if(index == digits.length()) {
            result.push_back(output);
            return;
        }
        
        int current_digit = digits[index] - '0';
        
        for(int i = 0; i < keypad[current_digit].length(); i++) {
            solve(digits, output + keypad[current_digit][i], index + 1, result);
        }
        
        return;
        
    }
    
    vector<string> letterCombinations(string digits) {
        
        vector<string> result;
        string output = "";
        
        if(digits.length() == 0) {
            return result;
        }
        
        solve(digits, output, 0, result);
        
        return result;
        
    }
};