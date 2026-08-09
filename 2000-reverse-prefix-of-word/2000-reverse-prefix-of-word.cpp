class Solution {
public:
    string reversePrefix(string w, char ch) {
        string s="";
        stack<char>st;
        int idx=0;
        for(int i=0;i<=w.size();i++){
            if(!st.empty() && ch==st.top()){
                idx=i;
                break;
            }
            st.push(w[i]);
        }
        if(idx==0)return w;
        while(!st.empty()){
            s+=st.top();
            st.pop();
        }

        while(idx<w.size()){
            s+=w[idx];
            idx++;
        }

        return s;

    }
};