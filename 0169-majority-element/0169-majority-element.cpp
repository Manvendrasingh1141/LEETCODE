class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int i=0,n=nums.size();
        int el = nums[0],cnt=0;
        while(i<n){
            if(el==nums[i])cnt++;
            else if(el!=nums[i])cnt--;

            if(cnt==0){
                el = nums[i];
                cnt=1;
            }
            i++;
        }

        return el;
    }
};