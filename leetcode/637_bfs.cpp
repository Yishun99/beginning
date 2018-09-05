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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ret;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int cnt = q.size();
            double sum = 0;
            for (int i = 0; i < cnt; i++) {
                TreeNode *now = q.front();
                sum += now->val;
                if (now->left) q.push(now->left);
                if (now->right) q.push(now->right);
                q.pop();
            }
            ret.push_back(sum / cnt);
        }
        return ret;
    }
};
