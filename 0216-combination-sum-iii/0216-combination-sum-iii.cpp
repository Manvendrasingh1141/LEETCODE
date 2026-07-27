class Solution {
public:
    vector<vector<int>>res;
    void combination(int k, int n,int idx,int sum,vector<int>&nums,vector<int>&temp){
        if(temp.size()==k){
            if(sum==n)res.push_back(temp);
            return;
        }

        if(sum>n)return;

        for(int i=idx;i<9;i++){
            temp.push_back(nums[i]);
            combination(k,n,i+1,sum+nums[i],nums,temp);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>nums;
        vector<int>temp;
        for(int i=0;i<9;i++)nums.push_back(i+1);
        combination(k,n,0,0,nums,temp);
        return res;
    }
};