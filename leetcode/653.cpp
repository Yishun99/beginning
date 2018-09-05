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
    int flag = 0;
    bool findTarget(TreeNode* root, int k) {
        set<int> st;
        dfs(root, st, k);
        if (flag) return true;
        else return false;
    }
    void dfs(TreeNode* root, set<int>& st, int k) {
        if (!root) return;
        if (st.find(root->val) != st.end()) { flag = 1; return; }
        st.insert(k - root->val);
        dfs(root->left, st, k);
        dfs(root->right, st, k);
    }
};
