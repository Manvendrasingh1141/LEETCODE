class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>m;
        for(int i=0;i<nums.size();i++){
            int need = target-nums[i];
            if(m.find(need)!=m.end()){
                return {m[need],i};
            }

            m[nums[i]]=i;
        }
        return {-1,-1};
    }
};