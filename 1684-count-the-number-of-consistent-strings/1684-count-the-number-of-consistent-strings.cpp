class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int>isallowed(26,0);
        int cnt=0;
        for(char c : allowed)isallowed[c-'a']++;
        for(int i=0;i<words.size();i++){
            string word = words[i];
            bool flag=0;
            for(char c : word)
            if(isallowed[c-'a']==0){
                flag=1;
                break;
            }
            if(flag==0)
            cnt++;
        }
        return cnt;
    }
};