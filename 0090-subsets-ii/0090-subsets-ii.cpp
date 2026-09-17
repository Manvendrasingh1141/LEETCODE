class Solution {
public:
    void fun(vector<vector<int>>&ans,vector<int>& res,vector<int>& nums,int idx){
        ans.push_back(res);
            
        for(int i=idx;i<nums.size();i++){
            if(i>idx && nums[i]==nums[i-1])continue;

            res.push_back(nums[i]);
            fun(ans,res,nums,i+1);
            res.pop_back();
        }
       
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>res;
        fun(ans,res,nums,0);
        return ans;
    }
    
};