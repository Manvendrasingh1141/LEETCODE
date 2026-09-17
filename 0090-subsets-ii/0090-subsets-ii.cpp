class Solution {
public:
    void subset(vector<int>& nums,vector<int>& temp,int idx,set<vector<int>>&res){
        if(idx==nums.size()){
            res.insert(temp);
            return;
        }
       
            //exclude
            subset(nums,temp,idx+1,res);
            //include
            temp.push_back(nums[idx]);
            subset(nums,temp,idx+1,res);
            temp.pop_back();
    
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>>res;
        vector<int>temp;
        subset(nums,temp,0,res);
        vector<vector<int>>ans(res.begin(),res.end());
        return ans;
    }
};