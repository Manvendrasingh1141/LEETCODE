class Solution {
public:
    string clearDigits(string s) {
        stack<char>st;
        string temp="";
        for(int i=0;i<s.size();i++){
            if(st.empty())st.push(s[i]);
            else if(isdigit(s[i])){
                if(isalpha(st.top()))st.pop();
                else st.push(s[i]);
            }else{
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            temp+=st.top();
            st.pop();
        }
        reverse(temp.begin(),temp.end());
        return temp;

    }
};