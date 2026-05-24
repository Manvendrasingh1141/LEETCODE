class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())return 0;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());

        int i=0,j=0;
        while(i<s.size()){
            if(s[i]!=t[j]){
                return 0;
            }
            i++;
            j++;
        }
        return 1;
    }
};