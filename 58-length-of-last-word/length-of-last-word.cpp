class Solution {
public:
    int lengthOfLastWord(string s) {
        string ans="";
        int j=0;
    for(int i=0;i<s.size();i++){
        if(s[i]==' '){
            ans="";
        }else{
            ans+=s[i];
            j=ans.size();
        }
    }
    return j;
    }
};