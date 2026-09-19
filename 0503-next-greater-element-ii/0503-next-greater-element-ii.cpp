class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>s;
        vector<int>v(nums.size(),-1);
        int n = nums.size();

        for(int i=0;i<nums.size()*2;i++){
            while(!s.empty() && nums[s.top()]<nums[i%n]){
                v[s.top()] = nums[i%n];
                s.pop();
            }

            s.push(i%n);
        }
        return v;
    }
};