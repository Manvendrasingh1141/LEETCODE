class Solution {
public:
    string sortVowels(string s) {
        vector<int> large(26,0);
        vector<int> small(26,0);

        for(int i=0;i<s.size();i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                small[s[i]-'a']++;
                s[i]='#';
            }
            else if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
                large[s[i]-'A']++;
                s[i]='#';
            }
        }

        string temp="", ans="";

        for(int i=0;i<26;i++){
            char c = i+'A';
            while(large[i]){
                temp += c;
                large[i]--;
            }
        }

        for(int i=0;i<26;i++){
            char c = i+'a';
            while(small[i]){
                temp += c;
                small[i]--;
            }
        }

        int i=0,j=0;

        while(i<s.size()){
            if(s[i]=='#'){
                ans += temp[j++];
            }
            else{
                ans += s[i];
            }
            i++;
        }

        return ans;
    }
};