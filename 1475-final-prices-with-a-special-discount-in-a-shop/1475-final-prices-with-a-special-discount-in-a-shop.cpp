class Solution {
public:
    vector<int> finalPrices(vector<int>& p) {
        vector<int>ans(p.begin(),p.end());
        stack<int>st;
        for(int i=0;i<p.size();i++){
            while(!st.empty() && p[st.top()]>=p[i]){
                ans[st.top()]=p[st.top()]-p[i];
                st.pop();
            }
            st.push(i);
        }

        return ans;
    }
};






