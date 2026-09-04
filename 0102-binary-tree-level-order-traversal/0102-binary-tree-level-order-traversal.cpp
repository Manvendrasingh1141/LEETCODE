class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)return ans;
        queue<TreeNode *>q;
        q.push(root);

        while(!q.empty()){
            vector<int>res;
            int n = q.size();
            while(n--){
                TreeNode * temp = q.front();
                res.push_back(temp->val);
                q.pop();

                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            } 
            ans.push_back(res);

        }
        return ans;
    }
};



