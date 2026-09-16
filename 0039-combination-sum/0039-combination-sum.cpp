class Solution {
public:
    void solve(vector<vector<int>> &ans,vector<int>& res,vector<int>& nums,
    int idx,int k,int &sum){
        if(sum>k || idx>nums.size()-1)return;
        if(sum==k){
            ans.push_back(res);
            return;
        }

        //accept 
        sum+=nums[idx];
        res.push_back(nums[idx]);
        solve(ans,res,nums,idx,k,sum);
        sum-=nums[idx];
        res.pop_back();


        //don't accecpt

        solve(ans,res,nums,idx+1,k,sum);
        
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int k) {
        vector<vector<int>>ans;
        vector<int>res;
        int sum=0;
        solve(ans,res,nums,0,k,sum);
        
        
        return ans;
    }
};