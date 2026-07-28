class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==1)return 0;
        for(int i=0;i<nums.size();i++){
            nums[i]-=1;
        }
        int lar=0,sec=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>lar && lar>=sec){
                sec = lar;
                lar = nums[i];
            }else if(nums[i]<=lar && nums[i]>sec){
                sec = nums[i];
            }
        }

        return (lar*sec);
    }
};

