class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>m(256,0);
        int i=0,j=0,mx=0;
        while(j<s.size()){
            while(m[s[j]]){
                m[s[i]]=0;
                i++;
            }

            m[s[j]]=1;
            mx=max(mx,j-i+1);
            j++;
        }
        return mx;
    }
};