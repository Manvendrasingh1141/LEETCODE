class Solution {
    public :
    int mySqrt(int x) {
        long start=1,end=(long)x;
        while(start<=end){
            long mid=start+(end-start)/2;
            if(mid*mid<=x){
                start=mid+1;
            }
            else end=mid-1;
        }
        return (int)end;
    }
};