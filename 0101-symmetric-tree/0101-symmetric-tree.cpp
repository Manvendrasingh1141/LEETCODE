class Solution {
public:
    bool check(TreeNode *p,TreeNode *q){
        if(!p && !q)return 1;
        if(!p || !q)return 0;
        if(p->val!=q->val)return 0;


        return check(p->left,q->right) && check(p->right,q->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)return 1;
        return check(root->left,root->right);

    }
};