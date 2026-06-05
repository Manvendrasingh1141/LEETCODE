class Solution {
public:
    int passwordStrength(string s) {
        set<char>st;
        for(int i=0;i<s.size();i++)st.insert(s[i]);

        int cnt=0;
        for(char x: st){
            if(x>='a' && x<='z')cnt+=1;
            else if(x>='A' && x<='Z')cnt+=2;
            else if(x>='0' && x<='9')cnt+=3;
            else if(x=='!' || x=='@' ||x=='#'||x=='$')cnt+=5;
        }

        return cnt;
    }
};