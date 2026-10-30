class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        ans.push_back({});
        giveans(nums, temp, 0,ans);

        return ans;
    }

    void giveans(vector<int>& nums, vector<int>& temp, int i, vector<vector<int>>& ans){

        if(i==nums.size()||temp.size()>nums.size()) return;

        temp.push_back(nums[i]);
        ans.push_back(temp);
        giveans(nums, temp, i+1,ans);
        temp.pop_back();
        giveans(nums, temp, i+1,ans);
    }
};