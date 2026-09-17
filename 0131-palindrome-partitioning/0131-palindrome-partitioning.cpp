class Solution {
public:
    bool isPalindrome(string &st){
        int s=0,e=st.size()-1;
        while(s<=e){
            if(st[s]!=st[e])return 0;
            s++;
            e--;
        }
        return 1;
    }
    void fun(vector<vector<string>>&ans,vector<string>&res,string s,int idx){
        if(idx>s.size()-1){
            ans.push_back(res);
            return;
        };

        
        for(int i=idx;i<s.size();i++){
            string temp = s.substr(idx,i-idx+1);
            if(isPalindrome(temp)){
                res.push_back(temp);
                fun(ans,res,s,i+1);
                res.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>res;
        fun(ans,res,s,0);
        return ans;
    }
};