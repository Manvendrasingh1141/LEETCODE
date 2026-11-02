class Solution {
public:
    bool search(vector<int>& nums, int k) {
       int start=0,end=nums.size()-1;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(nums[mid]==k)return 1;
            if(nums[start]==nums[mid] && nums[mid]==nums[end]){
                start+=1;
                end-=1;
                continue;
            }

            //left sorted condition
            if(nums[start]<=nums[mid]){
                // start <= k < mid (lies at left half)
                if(nums[start]<=k && k<nums[mid])end=mid-1;//eleminate right half
                else start=mid+1;
            }else{
                // mid<k<=end (lies at right half)
                if(nums[mid]<k && k<=nums[end])start=mid+1;//eleminate left half
                else end=mid-1;
            }
        }
        return 0; 
    }
};