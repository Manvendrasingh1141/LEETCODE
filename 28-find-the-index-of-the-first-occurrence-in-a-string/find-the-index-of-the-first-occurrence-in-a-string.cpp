class Solution {
public:
    int strStr(string s1, string s2) {
        int i=0,j=0,m=s1.size(),n=s2.size(),ans=-1;
        string s= "";
        for(int i=0;i<n;i++){
            s+=s1[i];
        }
        for(int i=n;i<=m;i++){
            if(s==s2)return i-n;
            else{
                s.erase(0,1);
                s+=s1[i];
            }
        }
        return -1;

    }
};