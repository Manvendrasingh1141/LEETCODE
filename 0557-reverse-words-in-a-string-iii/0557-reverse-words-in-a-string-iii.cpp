class Solution {
public:
    string reverse(string &s){
        int i=0,j=s.size()-1;
        while(i<=j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
        return s;
    }
    string reverseWords(string s) {
       for(int i=0;i<s.size();i++){
            if(s[i]==' ')s.erase(i,1);
            else break;
       }

       string w="",ans="";
       for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                ans+=reverse(w);
                ans+=" ";
                w="";
            }else w+=s[i];
       }

       ans+=reverse(w);
       return ans;
    }
};