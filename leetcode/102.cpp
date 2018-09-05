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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (root)
            bfs(root, ret);
        return ret;
    }
    void bfs(TreeNode* root, vector<vector<int>>& ret) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> tmp;
            int len = q.size();
            while (len--) {
                TreeNode* n = q.front();
                tmp.push_back(n->val);
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
                q.pop();
            }
            ret.push_back(tmp);
        }
    }
};
