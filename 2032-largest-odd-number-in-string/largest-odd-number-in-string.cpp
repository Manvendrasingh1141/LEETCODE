class Solution {
public:
    string largestOddNumber(string num) {
        int last,idx=-1;
        string ans="";
        for(int i=num.size()-1;i>=0;i--){
            last = num[i]-'0';
            if(last%2==1){
                idx = i;
                break;
            }
        }
        for(int i=0;i<=idx;i++)ans+=num[i];
        if(idx==-1)ans="";
        return ans;
    }
};