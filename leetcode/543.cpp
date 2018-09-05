
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
    int m = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        maxdepth(root);
        return m;
    }
    int maxdepth(TreeNode* root) {
        if (!root) return 0;
        int left = maxdepth(root->left), right = maxdepth(root->right);
        m = max(m, left + right);
        return max(left, right) + 1;
    }
};

