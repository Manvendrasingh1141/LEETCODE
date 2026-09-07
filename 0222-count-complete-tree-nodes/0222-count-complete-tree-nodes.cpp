class Solution {
public:
    int Lheight(TreeNode* root) {
        int cnt = 0;
        while(root) {
            cnt++;
            root = root->left;
        }
        return cnt;
    }

    int Rheight(TreeNode* root) {
        int cnt = 0;
        while(root) {
            cnt++;
            root = root->right;
        }
        return cnt;
    }

    int countNodes(TreeNode* root) {
        if(!root) return 0;

        int l = Lheight(root);
        int r = Rheight(root);

        if(l==r)return pow(2, l) - 1;

        return 1 +countNodes(root->left)+countNodes(root->right);
    }
};