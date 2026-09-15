class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(!root)return ans;


        //Morris Traversal
        while(root){
            //left part doesn't exsists
            if(!root->left){
                ans.push_back(root->val);
                root = root->right;
            }

            //left part exists
            else{
                //create one current node and go to right;
                TreeNode *curr = root->left;
                while(curr->right && curr->right!=root)curr=curr->right;

                //curr->right == NULL
                if(curr->right == NULL){
                    //create a link and move to left
                    curr->right = root;
                    root = root->left;
                }
                //curr->right == root->val
                else{
                    //remove the link first , store the value and move to right
                    curr->right = NULL;
                    ans.push_back(root->val);
                    root = root->right;
                }
            }
        }

        return ans;
    }
};