class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        deque<int>d;
        for(int i=0;i<k-1;i++){
            if(d.empty())d.push_back(i);
            else{
                while(!d.empty() && nums[d.back()]<nums[i]){
                    d.pop_back();
                }
                d.push_back(i);
            }
        }
    
        for(int i=k-1;i<nums.size();i++){
            while(!d.empty() && nums[d.back()]<nums[i]){
                    d.pop_back();
                }
                d.push_back(i);
            
            if(i-k>=d.front())d.pop_front();
    
            ans.push_back(nums[d.front()]);
        }
        return ans;
    }
};


