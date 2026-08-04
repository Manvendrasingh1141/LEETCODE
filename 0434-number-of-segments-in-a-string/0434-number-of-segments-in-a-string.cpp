class Solution {
public:
    int countSegments(string s) {
        int cnt=0;
        string temp="";
        for(int i=0;i<s.size();i++){
            if(temp!="" && s[i]==' '){
                cnt++;
                temp="";
            }
            else if(s[i]!=' ')temp+=s[i];
        }
        if(temp!="")cnt++;
        return cnt;
    }
};