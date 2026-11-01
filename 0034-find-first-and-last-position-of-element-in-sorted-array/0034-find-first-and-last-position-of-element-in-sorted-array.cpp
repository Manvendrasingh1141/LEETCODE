class Solution {
public:
    int findFirst(vector<int>& nums, int target){
        int ans=-1,s=0,e=nums.size()-1;
        while(s<=e){
            int m = s+(e-s)/2;
            if(nums[m]<target)s=m+1;
            else if(nums[m]>=target){
                if(nums[m]==target)ans=m;
                e=m-1;
                }
        }
        return ans;
    }
    int findLast(vector<int>& nums, int target){
        int ans=-1,s=0,e=nums.size()-1;
        while(s<=e){
            int m = s+(e-s)/2;
            if(nums[m]<=target){
                if(nums[m]==target)ans=m;
                s=m+1;
            }
            else if(nums[m]>target)e=m-1;
        }
        return ans;  
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int f = findFirst(nums,target);
        int l = findLast(nums,target);
        return {f,l};
    }
};