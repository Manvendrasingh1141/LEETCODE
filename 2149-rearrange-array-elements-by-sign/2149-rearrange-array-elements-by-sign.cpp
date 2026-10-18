class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>pos;
        vector<int>neg;

        for(int x : nums){
            if(x>0)pos.push_back(x);
            else neg.push_back(x);
        }

        int i=0,j=0;
        while(i<pos.size()){
            nums[i*2] = pos[i];
            i++;
        }
        while(j<neg.size()){
            nums[j*2+1] = neg[j];
            j++;
        }
        return nums;
    }
};