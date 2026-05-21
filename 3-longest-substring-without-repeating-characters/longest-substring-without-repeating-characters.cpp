class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool>v(256);
        string ans="";
        int i=0,j=0,mx=0;
        while(j<s.size()){
            while(v[s[j]]){
                v[s[i]]=0;
                i++;
            }

            v[s[j]]=1;
            mx=max(mx,j-i+1);
            j++;
        }
        return mx;
    }
};