class Solution {
public:
    int x = -1;
    int height(TreeNode* root) {
        if(!root)return 0;

        return 1+(max(height(root->left),height(root->right)));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        x = max(x,height(root->left)+height(root->right));

        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        return x;
    }
};