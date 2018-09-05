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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<TreeNode*> v;
            int len = q.size();
            for (int i = 0; i < len; i++) {
                v.push_back(q.front());
                q.pop();
            }
            for (int i = 0, j = v.size() - 1; i <= j; i++, j--) {
                if (v[i] == NULL && v[j] == NULL) continue;
                else if (v[i] == NULL || v[j] == NULL) return false;
                else if (v[i]->val != v[j]->val) return false;
            }
            for (int i = 0; i < v.size(); i++)
                if (v[i]) { q.push(v[i]->left); q.push(v[i]->right); }
        }
        return true;
    }
};
