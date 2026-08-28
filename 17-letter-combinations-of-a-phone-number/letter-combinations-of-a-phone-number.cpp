class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.empty()) return ans;

        string temp;
        map<int, vector<char>> mp = {
            {2, {'a', 'b', 'c'}},    
            {3, {'d', 'e', 'f'}},
            {4, {'g', 'h', 'i'}},
            {5, {'j', 'k', 'l'}},
            {6, {'m', 'n', 'o'}},
            {7, {'p', 'q', 'r', 's'}},
            {8, {'t', 'u', 'v'}},
            {9, {'w', 'x', 'y', 'z'}}
        };

        check(mp, digits, 0, temp, ans);
        return ans;
    }

    void check(map<int, vector<char>>& mp, const string& digits, int index, string& temp, vector<string>& ans) {
        if (index == digits.length()) {
            ans.push_back(temp);
            return;
        }

        int digit = digits[index] - '0';
        for (char ch : mp[digit]) {
            temp.push_back(ch);
            check(mp, digits, index + 1, temp, ans);
            temp.pop_back();
        }
    }
};