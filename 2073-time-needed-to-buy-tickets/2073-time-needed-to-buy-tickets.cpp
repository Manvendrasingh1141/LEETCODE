class Solution {
public:
    int timeRequiredToBuy(vector<int>& nums, int k) {
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(i<=k)cnt+=min(nums[k],nums[i]);
            else cnt+=min(nums[k]-1,nums[i]);
        }
        return cnt;
    }
};