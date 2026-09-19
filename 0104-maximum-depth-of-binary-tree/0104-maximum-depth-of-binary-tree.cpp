class Solution {
public:
    int Height(TreeNode* root){
        if(!root)return 0;

        return 1+max(Height(root->left),Height(root->right));
    }
    int maxDepth(TreeNode* root) {
        if(!root)return 0;
        return Height(root);
    }
};