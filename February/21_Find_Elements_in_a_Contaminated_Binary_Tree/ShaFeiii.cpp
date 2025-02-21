/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class FindElements { // 27.10% Time - 82.80% Memory
    unordered_map<int, bool> exist;
    void build(TreeNode* node) {
        if (!node) return;
        if (node->left) {
            node->left->val = 2 * node->val + 1;
            cout << node->left->val << ' ';
            exist[node->left->val] = true;
        }
        if (node->right) {
            node->right->val = 2 * node->val + 2;
            cout << node->right->val << ' ';
            exist[node->right->val] = true;
        }
        build(node->left);
        build(node->right);
    }
public:
    FindElements(TreeNode* root) {
        root->val = 0;
        exist[root->val] = 0;
        build(root);
    }
    
    bool find(int target) {
        return exist.find(target) != exist.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */



 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class FindElements { // 73.64% Time - 44.67 Memory
    unordered_map<int, bool> exist;
    void build(TreeNode* node, int cur) {
        if (!node) return;
        exist[cur] = true;
        build(node->left, 2 * cur + 1);
        build(node->right, 2 * cur + 2);
    }
public:
    FindElements(TreeNode* root) {
        build(root, 0);
    }
    
    bool find(int target) {
        return exist.find(target) != exist.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */