class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> current;
        check(k, 1, n, current, ans);
        return ans;
    }

    void check(int k, int ind, int target, vector<int>& current, vector<vector<int>>& ans) {
        if (target == 0 && current.size() == k) {
            ans.push_back(current);
            return;
        }

        if (target < 0 || current.size() > k || ind > 9) return;

        current.push_back(ind);
        check(k, ind + 1, target - ind, current, ans);

        current.pop_back();
        check(k, ind + 1, target, current, ans);
    }
};