class Solution {
public:

    void fun(vector<vector<int>>&ans,vector<int>&res,vector<int>&nums,int idx,int &sum,int k){
        if(sum>k)return;

        if(sum==k){
            ans.push_back(res);
            return;
        }

        for(int i=idx;i<nums.size();i++){
            if(i>idx && nums[i]==nums[i-1])continue;
            sum+=nums[i];
            res.push_back(nums[i]);
            fun(ans,res,nums,i+1,sum,k);
            sum-=nums[i];
            res.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>res;
        int sum=0;
        fun(ans,res,nums,0,sum,k);

        return ans;
    }
};