class Solution {
public:

    void merge(vector<int>&nums,int start,int mid,int end){
        vector<int>v;
        int left = start , right = mid+1;
        while(left<=mid && right<=end){
            if(nums[left]<=nums[right]){
                v.push_back(nums[left]);
                left++;
            }
            else{
                v.push_back(nums[right]);
                right++;
            }
        }

        while(left<=mid){
            v.push_back(nums[left]);
            left++;
        }
        while(right<=end){
            v.push_back(nums[right]);
            right++;
        }

        for(int i=start;i<=end;i++){
            nums[i]=v[i-start];
        }
    }
    void mergesort(vector<int>&nums,int start,int end){
        if(start>=end)return;
        int mid = start+(end-start)/2;
        mergesort(nums,start,mid); //left
        mergesort(nums,mid+1,end); //right

        merge(nums,start,mid,end);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums,0,nums.size()-1);
        return nums;
    }
};