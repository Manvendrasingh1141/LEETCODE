class Solution {
public:
    int concatenate(int f,int l){
        int n=l;
        while(n){
            f*=10;
            n=n/10; 
        }

        return f+l;
        
        
    }
    long long findTheArrayConcVal(vector<int>& nums) {
        long long n=1,sum=0,i=0,j=nums.size()-1;
        while(i<j){
            int f=nums[i],l=nums[j];
            sum+=concatenate(f,l);
            i++;
            j--;
        }
        if(nums.size()%2!=0)sum+=nums[nums.size()/2];
        return sum;
    }
};