class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0)return 0;

        int long_cnt=0;
        unordered_set<int>st;
        for(int i=0;i<n;i++){
           st.insert(nums[i]);
        }

        for(auto it: st){
            /*
            by this condition we are saving our time - because we are
            skipping those elements which are the mid of any sequence 
            eg. 2 - mid of sequence {1,2,3,4};
            so by this condition we save iteration - {2,3,4}
            */
            if(st.find(it-1)==st.end()){
                int el = it;
                int cnt=1;
                while(st.find(el+1)!=st.end()){
                    cnt++;
                    el++;
                }
                long_cnt = max(long_cnt,cnt);
            }
        }

        return long_cnt;
    }
};