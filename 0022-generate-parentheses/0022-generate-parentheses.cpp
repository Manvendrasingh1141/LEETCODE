class Solution {
public:
    void generate(vector<string>&ans,string&temp,int l,int r,int n){
        if(r+l==2*n){
            ans.push_back(temp);
            return;
        }
        //left present
        if(l<n){
            temp.push_back('(');
            generate(ans,temp,l+1,r,n);
            temp.pop_back();
        }if(r<l){
            temp.push_back(')');
            generate(ans,temp,l,r+1,n);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string temp;
        generate(ans,temp,0,0,n);
        return ans;
    }
};