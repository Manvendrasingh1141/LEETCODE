class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        unordered_set<int>s;
        int m=1;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        for(auto it : s){
            if(s.find(it-1)==s.end()){
                int el=it;
                int cnt=1;
                while(s.find(el+1)!=s.end()){
                    cnt++;
                    el+=1;
                }
                m=max(m,cnt);
            }
        }
        return m;
    }
};