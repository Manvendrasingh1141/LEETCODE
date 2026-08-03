class Solution {
public:
    bool check(char c){
        if(c>='a' && c<='z')return 1;

        return 0;
    }
    string reverseByType(string s) {
        int i=0,j=s.size()-1;
        while(i<=j){
            if(check(s[i]) && check(s[j])){
                swap(s[i],s[j]);
                i++;
                j--;
                }  
            else{
                while(i<=j && !check(s[i]))i++;
                while(i<=j &&  !check(s[j]))j--;
            }
        }


        i=0,j=s.size()-1;
        while(i<=j){
            if(!check(s[i]) && !check(s[j])){
                swap(s[i],s[j]);
                i++;
                j--;
                }  
            else{
                while(i<=j &&  check(s[i]))i++;
                while(i<=j &&  check(s[j]))j--;
            }
        }

        return s;

    }
};