class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(!root)return ans;

        deque<TreeNode *>q;
        q.push_back(root);

        while(!q.empty()){
            TreeNode *temp = q.front();
            ans.push_back(q.back()->val);
            int n = q.size();
            while(n--){
            TreeNode *x = q.front();
            q.pop_front();

            if(x->left)q.push_back(x->left);
            if(x->right)q.push_back(x->right);
            }

        }
        return ans;
    }
};