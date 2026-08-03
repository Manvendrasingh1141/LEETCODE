class Solution {
public:
    int s1=0,s2=0;
    void sumOUT(int n,int m,int i){
        if(i>n)return;
        if(i%m==0)s1+=i;
        if(i%m!=0)s2+=i;
        sumOUT(n,m,i+1);
    }
    int differenceOfSums(int n, int m) {
        sumOUT(n,m,1);
        return s2-s1;
    }
};