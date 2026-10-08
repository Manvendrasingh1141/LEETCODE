class Solution {
public:

    int ans = 0;

    int DFS(TreeNode* node) {
        if (node == NULL)
            return INT_MIN;

        int leftMax = DFS(node->left);
        int rightMax = DFS(node->right);

        int subtreeMax = max(node->val, max(leftMax, rightMax));

        if (node->val == subtreeMax)
            ans++;

        return subtreeMax;
    }

    int countDominantNodes(TreeNode* root) {
        DFS(root);
        return ans;
    }
};