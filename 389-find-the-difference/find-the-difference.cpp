class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans = ' ';
        vector<int>sv(26,0);
        vector<int>tv(26,0);
        for(int i=0;i<s.size();i++){sv[s[i]-'a']++;}
        for(int i=0;i<t.size();i++){tv[t[i]-'a']++;}

        for(int i=0;i<26;i++){
            if(sv[i]!=tv[i]){
                ans = i + 'a';
                break;
            }
        }

        return ans;
    }
};