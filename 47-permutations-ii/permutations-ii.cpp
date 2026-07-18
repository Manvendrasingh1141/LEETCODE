class Solution {
public:
    void fun(vector<int>& nums,vector<int>&temp,vector<bool>&visited,set<vector<int>>&ans){
        if(temp.size()==nums.size()){
            ans.insert(temp);
            return;
        }

        for(int i=0;i<visited.size();i++){
            if(visited[i]==0){
                temp.push_back(nums[i]);
                visited[i]=1;
                fun(nums,temp,visited,ans);
                temp.pop_back();
                visited[i]=0;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>>ans;
        vector<int>temp;
        vector<bool>visited(nums.size(),0);
        fun(nums,temp,visited,ans);
        vector<vector<int>>res(ans.begin(),ans.end());
        return res;
    }
};

