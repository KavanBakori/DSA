class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> current;

        check(candidates, target, 0, current, ans);

        return ans;
    }

    void check(vector<int>& nums, int sum, int ind, vector<int>& current, vector<vector<int>>& ans){
        if(sum < 0 || ind >= nums.size()) return;

        if(sum==0){
            ans.push_back(current);
            return;
        }
        current.push_back(nums[ind]);
        check(nums, sum-nums[ind], ind, current, ans);
        current.pop_back();
        check(nums, sum, ind+1, current, ans);
    }

};