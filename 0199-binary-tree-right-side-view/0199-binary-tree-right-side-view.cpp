class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(!root)return ans;

        deque<TreeNode *>q;
        q.push_back(root);

        while(!q.empty()){

            ans.push_back(q.back()->val);
            int n = q.size();

            while(n--){
            
            TreeNode *temp = q.front();
            q.pop_front();

            if(temp->left)q.push_back(temp->left);
            if(temp->right)q.push_back(temp->right);
            }

        }
        return ans;
    }
};