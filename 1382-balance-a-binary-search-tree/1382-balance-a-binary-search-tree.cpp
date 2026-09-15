class Solution {
public:
    class Node {
    public:
        int data, height;
        Node *left, *right;

        Node(int val) {
            data = val;
            left = right = NULL;
            height = 1;
        }
    };

    int getHeight(Node* root) {
        if (!root)
            return 0;

        return root->height;
    }

    int getBalance(Node* root) {
        return getHeight(root->left) - getHeight(root->right);
    }

    Node* rightRotation(Node* root) {
        Node* child = root->left;
        Node* childRight = child->right;

        child->right = root;
        root->left = childRight;

        // update heights
        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        child->height =
            1 + max(getHeight(child->left), getHeight(child->right));

        return child;
    }

    Node* leftRotation(Node* root) {
        Node* child = root->right;
        Node* childLeft = child->left;

        child->left = root;
        root->right = childLeft;

        // update heights
        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        child->height =
            1 + max(getHeight(child->left), getHeight(child->right));

        return child;
    }

    Node* createAVL(Node* root, int key) {

        if (!root) {
            return new Node(key);
        }

        if (root->data > key) {
            root->left = createAVL(root->left, key);
        } else if (root->data < key) {
            root->right = createAVL(root->right, key);
        } else {
            return root; // duplicate
        }

        // update height
        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        // calculate balance
        int balance = getBalance(root);

        // LL
        if (balance > 1 && key < root->left->data) {
            return rightRotation(root);
        }

        // LR
        else if (balance > 1 && key > root->left->data) {
            root->left = leftRotation(root->left);
            return rightRotation(root);
        }

        // RL
        else if (balance < -1 && key < root->right->data) {
            root->right = rightRotation(root->right);
            return leftRotation(root);
        }

        // RR
        else if (balance < -1 && key > root->right->data) {
            return leftRotation(root);
        }

        return root;
    }

    // Store all elements of original BST
    void storeValues(TreeNode* root, vector<int>& values) {
        if (!root)
            return;

        values.push_back(root->val);

        storeValues(root->left, values);
        storeValues(root->right, values);
    }

    // Convert AVL Node -> TreeNode
    TreeNode* convertToTreeNode(Node* root) {
        if (!root)
            return NULL;

        TreeNode* newRoot = new TreeNode(root->data);

        newRoot->left = convertToTreeNode(root->left);
        newRoot->right = convertToTreeNode(root->right);

        return newRoot;
    }

    TreeNode* balanceBST(TreeNode* root) {

        // Step 1: Store all elements
        vector<int> values;

        storeValues(root, values);

        // Step 2: Create AVL
        Node* avlRoot = NULL;

        for (int value : values) {
            avlRoot = createAVL(avlRoot, value);
        }

        // Step 3: Convert Node tree back to TreeNode
        return convertToTreeNode(avlRoot);
    }
};