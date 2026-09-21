class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        map<int, int> mp;
        int re, no;

        for(int i=1;i<=grid.size()*grid.size();i++){
            mp[i]=0;
        }
        for(int i=0;i<grid.size();i++){
            for (int j=0;j<grid[0].size();j++){
                mp[grid[i][j]]++;
            }
        }

        for(auto a:mp){
            if(a.second==0){
                no = a.first;
            }
            if(a.second==2){
                re = a.first;
            }
        }

        return {re, no};
    }
};