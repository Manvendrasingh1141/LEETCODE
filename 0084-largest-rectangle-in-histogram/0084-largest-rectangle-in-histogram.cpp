class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        vector<int>leftSmallest(h);
        vector<int>rightSmallest(h);
        stack<int>st;
        for(int i=0;i<h.size();i++){
            while(!st.empty() && h[st.top()]>h[i]){
                rightSmallest[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        while(!st.empty()){
            rightSmallest[st.top()]=h.size();
            st.pop();
        }


        for(int i=h.size()-1;i>=0;i--){
            while(!st.empty() && h[st.top()]>h[i]){
                leftSmallest[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        while(!st.empty()){
            leftSmallest[st.top()]=-1;
            st.pop();
        }

        int ans=0;
        for(int i=0;i<h.size();i++){
            ans = max(ans, h[i]*(rightSmallest[i]-leftSmallest[i]-1));
        }

        return ans;
    }
};