class Solution {
public:
    int timeRequiredToBuy(vector<int>& nums, int k) {
        queue<int>q;
        int cnt=0;
        for(int i=0;i<nums.size();i++)q.push(i);

        while(nums[k]!=0){
            nums[q.front()]--;
            if(nums[q.front()]) 
                q.push(q.front());
                q.pop();
                cnt++;
            
        }
        return cnt;
    }
};