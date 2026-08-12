class Solution {
public:
    int revNum(int num){
        int x=num,rev=0,temp;
        while(x){
            temp = x%10;
            rev=rev*10+temp;
            x/=10;
        }

        return rev;

    }
    bool isSameAfterReversals(int num) {
        int n = revNum(num);
        if(num==revNum(n))return 1;
        return 0;
    }
};