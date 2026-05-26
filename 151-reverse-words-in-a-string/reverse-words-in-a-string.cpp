class Solution {
public:
    string reverse(string s){
        int i=0,j=s.size()-1;
        while(i<=j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
        return s;
    }
    string reverseWords(string s) {
        string temp="",ans="";

        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==' '){
                if(temp=="")continue;
                ans+=reverse(temp);
                ans+=" ";
                temp="";
            }

            else if(s[i]!=' '){
                temp+=s[i];
            }
        }
        ans+=reverse(temp);
        int k = ans.size()-1;
        if(ans[k]==' ')ans.pop_back();
        return ans;
    }
};