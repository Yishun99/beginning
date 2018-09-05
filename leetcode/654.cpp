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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size() == 0) return NULL;
        int mx = nums[0], ix = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (mx < nums[i]) { mx = nums[i]; ix = i; }
        }
        TreeNode* root = new TreeNode(mx);
        vector<int> lnums;
        vector<int> rnums;
        for (int i = 0; i < ix; i++) lnums.push_back(nums[i]);
        for (int i = ix + 1; i < nums.size(); i++) rnums.push_back(nums[i]);
        root->left = constructMaximumBinaryTree(lnums);
        root->right = constructMaximumBinaryTree(rnums);
        return root;
    }
};
