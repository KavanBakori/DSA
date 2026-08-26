class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;
        sort(nums.begin(),nums.end());
        ans.push_back({});
        check(nums,0,current,ans);

        return ans;
    }

    void check(vector<int>& nums,int ind, vector<int>& current, vector<vector<int>>& ans){
        
        if(ind>=nums.size()) return;
        
        current.push_back(nums[ind]);

        ans.push_back(current);


        check(nums,ind+1,current,ans);
        current.pop_back();

        while (ind + 1 < nums.size() && nums[ind] == nums[ind + 1]) {
            ind++;
        }
        check(nums,ind+1,current,ans);

    }
};