class Solution {
public:
    void solve(vector<vector<int>> &res,vector<int> &arr, 
    vector<int> &temp,int target,int i,int sum) {
        
        if(sum>target)return;
        
        if(sum==target){
            res.push_back(temp);
            return;
        }
        for(int j=i;j<arr.size();j++){
            temp.push_back(arr[j]);
            solve(res,arr,temp,target,j,sum+arr[j]);
            temp.pop_back();
        }
        
        
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>>res;
        vector<int>temp;
        solve(res,arr,temp,target,0,0);
        return res;
    }
};