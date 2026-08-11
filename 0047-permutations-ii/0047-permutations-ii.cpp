class Solution {
public:
    void fun(vector<int>& nums, int idx, vector<vector<int>>& ans) {
        if (idx == nums.size()) {
            ans.push_back(nums);
            return;
        }
        vector<bool> visited(21, 0);   
        for (int i = idx; i < nums.size(); i++) {
            if (visited[nums[i] + 10])
                continue;
            visited[nums[i] + 10] = 1;
            swap(nums[idx], nums[i]);
            fun(nums, idx + 1, ans);
            swap(nums[idx], nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        fun(nums, 0, ans);
        return ans;
    }
};