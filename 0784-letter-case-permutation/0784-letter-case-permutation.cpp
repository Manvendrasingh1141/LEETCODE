class Solution {
public:
    void letters(vector<string>&res,string temp,string s,int idx){
        if(idx==s.size()){
            res.push_back(temp);
            return;
        }
        if(s[idx]>='0' && s[idx]<='9'){
            temp.push_back(s[idx]);
            letters(res,temp,s,idx+1);
        }else{
        temp.push_back(s[idx]);
        letters(res,temp,s,idx+1);
        temp.pop_back();

        if(s[idx]>='a' && s[idx]<='z')temp+=(s[idx]+'A'-'a');
        else if(s[idx]>='A' && s[idx]<='Z')temp+=(s[idx]-'A'+'a');
        letters(res,temp,s,idx+1);
        temp.pop_back();
        }
        
    }
    vector<string> letterCasePermutation(string s) {
        vector<string>res;
        string temp="";
        letters(res,temp,s,0);
        return res;
    }
};


// C = 67
// a= 97 A = 65
// c= 99
