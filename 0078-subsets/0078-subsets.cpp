class Solution {
public:
    void fun(vector<vector<int>>&ans,vector<int>& res,vector<int>& nums,int idx){
        if(idx>nums.size()-1){
            ans.push_back(res);
            return;
        }

        
            //pick 
            res.push_back(nums[idx]);
            fun(ans,res,nums,idx+1);
            res.pop_back();

            //not pick
            fun(ans,res,nums,idx+1);
       
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>res;
        fun(ans,res,nums,0);
        return ans;
    }
    
};