class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt=0;
        string ans="",temp="";
        for(int i=0;i<s.size();i++){
            temp+=s[i];
            if(s[i]=='(')cnt++;
            else if(s[i]==')')cnt--;

            if(cnt==0){
                temp.erase(0,1);
                temp.pop_back();
                ans+=temp;
                temp="";
            }
        }
        return ans;
    }
};