class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        q.push(root);
        vector<long long> sums;

        while (!q.empty()) {
            int n = q.size();
            long long sum = 0;

            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                sum += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            sums.push_back(sum);
        }
        sort(sums.rbegin(), sums.rend());
        if (k > sums.size()) return -1;
        return sums[k - 1];
    }
};