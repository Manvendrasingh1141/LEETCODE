class Solution {
public:
    int chairsCnt(int m,string s){
        int cnt=0,c;
        for(int i=0;i<s.size();i++){
            if(s[i]=='E')cnt++;
            else if(s[i]=='L')cnt--;
            c = m-cnt;
            if(c<0)return -1;
        }
        return 1;
    } 
    int minimumChairs(string s) {
        int start=0,end=s.size(),res=INT_MAX;
        while(start<=end){
            int mid = start+(end-start)/2;
            int check = chairsCnt(mid,s);
            if(check>0){
                res=min(mid,res);
                end = mid - 1;
            }else{
                start = mid + 1;
            } 
        }
        return res;
    }
};