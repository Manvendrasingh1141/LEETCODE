class Solution {
public:
    int findLucky(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int el=nums[0],cnt=1,ans=-1;
        for(int i=0;i<nums.size()-1;i++){
            if(el==nums[i+1]){
                cnt++;
            }else if(el!=nums[i+1]){
                if(el==cnt)ans=max(ans,el);
                cnt=1;
                el=nums[i+1];
            }
        }
        if(el==cnt)ans=max(ans,el);
        return ans;
    }
};


