/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) return res;
        TreeNode* node = root;
        while (node != NULL) {
            if (node->left == NULL) {
                res.push_back(node->val);
                node = node->right;
            } else {
                TreeNode* pre = node->left;
                while (pre->right != NULL && pre->right != node) 
                    pre = pre->right;
                if (pre->right == NULL) {
                    pre->right = node;
                    node = node->left;
                } else if (pre->right == node) {
                    res.push_back(node->val);
                    pre->right = NULL;
                    node = node->right;
                }
            }
        }
        return res;
    }
}; 
