class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int i=0,cnt=0,sum=0,n=nums.size();
        map<int,int>mp;
        mp[0]=1;
        while(i<n){
            sum+=nums[i];
            int need = sum-k;
            if(mp.find(need)!=mp.end()){
                cnt+=mp[need];
            }
            mp[sum]++;
            i++;
        }
        return cnt;
    }
};