class Solution {
public:
    int getSize(int n){
        int d=0;
        while(n){
            d++;
            n/=10;
        }
        return d;
    }
    int countCommas(int num) {
        int n=getSize(num);
        if(n<4)return 0;
        else if(n>3 && n<=5)return num-1000+1;
        return num-1000+1;
    }
};


