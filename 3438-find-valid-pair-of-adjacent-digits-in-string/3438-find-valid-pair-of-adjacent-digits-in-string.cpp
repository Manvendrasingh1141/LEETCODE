class Solution {
public:
    string findValidPair(string s) {
        vector<int>c(10,0);
        for(char x:s){
            c[x-'0']++;
        }
        for(int i=0;i<s.size()-1;i++){
            int f=s[i]-'0',l=s[i+1]-'0';
            if(f!=l && f==c[f] && l==c[l])return s.substr(i,2);
        }
        
        return "";
    }
};
