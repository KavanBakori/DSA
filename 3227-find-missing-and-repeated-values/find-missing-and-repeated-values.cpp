class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int total = n * n;
        
        vector<int> mp(total + 1, 0);
        int re = -1, no = -1;

        for(int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                mp[grid[i][j]]++;
            }
        }

        for(int i = 1; i <= total; i++){
            if(mp[i] == 0){
                no = i;
            } else if(mp[i] == 2){
                re = i;
            }
        }

        return {re, no};
    }
};