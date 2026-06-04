class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int s=0,m=INT_MIN;
        for(int i=0;i<nums.size();i++){
            s = max(nums[i],s+nums[i]);
            m = max(m,s);
        }
        return m;
    }
};