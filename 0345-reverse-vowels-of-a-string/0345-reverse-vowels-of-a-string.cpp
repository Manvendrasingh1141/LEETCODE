class Solution {
public:
    bool vowel(char c){
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')return 1;
        return 0;
    }
    string reverseVowels(string s) {
        vector<char>v;
        string ans="";
        int i=0;
        for(char x : s){
            if(vowel(x))v.push_back(x);
        }

        reverse(v.begin(),v.end());
        for(char x : s){
            if(vowel(x)){
                ans+=v[i];
                i++;
            }else{
                ans+=x;
            }
        }
        return ans;
    }
};


