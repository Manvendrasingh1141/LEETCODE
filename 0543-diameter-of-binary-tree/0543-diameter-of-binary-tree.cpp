class Solution {
public:

    int height(TreeNode* root,int &cnt){
        if(!root)return 0;

        int l = height(root->left,cnt);
        int r = height(root->right,cnt);

        cnt = max(cnt,l+r);

        return 1+max(l,r);

    }
    int diameterOfBinaryTree(TreeNode* root) {
        int cnt=0;
        height(root,cnt);
        return cnt;
        
    }
};