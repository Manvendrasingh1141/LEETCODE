class Solution {
public:
    void fun(vector<int>& nums,vector<int>&temp,vector<bool>&visited,vector<vector<int>>&ans){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
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
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        vector<bool>visited(nums.size(),0);
        fun(nums,temp,visited,ans);

        return ans;
    }
};