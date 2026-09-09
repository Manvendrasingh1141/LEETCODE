class Solution {
public:
    void inorder(int &ans,TreeNode *root,int &k){
        if(!root)return;

        inorder(ans,root->left,k);
        
        k--;
        if(k>=0)ans=root->val;
        if(k<0)return;

        inorder(ans,root->right,k);
        

        
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans=0;
        inorder(ans,root,k);
        return ans;
    }
};