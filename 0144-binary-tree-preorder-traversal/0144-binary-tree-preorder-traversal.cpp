class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>v;
        if(!root)return v;
        
        deque<TreeNode *>q;
        q.push_back(root);

        while(!q.empty()){
            TreeNode *temp = q.front();
            q.pop_front();
            v.push_back(temp->val);

            if(temp->right)q.push_front(temp->right);
            if(temp->left)q.push_front(temp->left);
        }
        return v;
    }
};