class Solution {
public:
    void reverse(int i,int j,string &s){
        while(i<=j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
    }
    string toHex(int num) {
        string temp="",digit="0123456789abcdef";
        unsigned int n = num;
        if(n==0)return "0";
        while(n>0){
            int rem = n%16;
            temp+=digit[rem];
            n=n/16;
        }
        reverse(0,temp.size()-1,temp);
        return temp;
    }
};