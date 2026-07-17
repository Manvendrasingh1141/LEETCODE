class Solution {
public:
    int firstPos(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int ans = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                ans = mid;
                r = mid - 1;   // move left
            }
            else if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return ans;
    }

    int lastPos(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int ans = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                ans = mid;
                l = mid + 1;   // move right
            }
            else if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};

        int first = firstPos(nums, target);
        if (first == -1) return {-1, -1};

        int last = lastPos(nums, target);
        return {first, last};
    }
};