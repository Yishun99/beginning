/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
const int maxn = 1000;
class Solution {
public:
    int cnt[maxn];
    double sum[maxn];
    vector<double> averageOfLevels(TreeNode* root) {
        dfs(0, root);
        vector<double> ret;
        for(int i = 0; i < maxn; i++) {
            if (!cnt[i]) break;
            ret.push_back(sum[i] / cnt[i]);
        }
        return ret;
    }
    void dfs(int cur, TreeNode* root) {
        if (!root) return;
        sum[cur] += root->val;
        cnt[cur]++;
        dfs(cur+1, root->left);
        dfs(cur+1, root->right);
    }
};
