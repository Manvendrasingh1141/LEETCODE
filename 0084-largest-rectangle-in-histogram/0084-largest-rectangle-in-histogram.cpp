class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        stack<int>st;
        int ans=0,idx=0,n=nums.size();
        for(int i=0;i<nums.size();i++){
            while(!st.empty() && nums[st.top()]>nums[i]){
                idx = st.top();
                st.pop();
                if(!st.empty())ans=max(ans,nums[idx]*(i-st.top()-1));
                else ans=max(ans,nums[idx]*i);
            }
            st.push(i);
            }
            while(!st.empty()){
                idx = st.top();
                st.pop();
                if(!st.empty())ans=max(ans,nums[idx]*(n-st.top()-1));
                else ans=max(ans,nums[idx]*n);
        }
        return ans;
    }
};