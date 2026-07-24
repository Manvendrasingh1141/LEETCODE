class Solution {
public:
    void combinations(int idx,int n,char &c,string s,string &temp,vector<string>&ans){
        if(temp.size()==s.size()){
            ans.push_back(temp);
            return;
        }
        string st[] = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        n = s[idx]-'0';
        for(int i=0;i<st[n].size();i++){
            c = st[n][i];
            temp+=c;
            idx+=1;
            combinations(idx,n,c,s,temp,ans);
            temp.pop_back();
            idx-=1;
        }
    }
    vector<string> letterCombinations(string d) {
        vector<string>ans;
        string temp="";
        char c = ' ';  
        combinations(0,0,c,d,temp,ans);
        return ans;
    }
};



                //     2                3
                //    1      2           3
                // 1 2 3   1 2 3       1 2 3


                // a b c
                // 97 98 99