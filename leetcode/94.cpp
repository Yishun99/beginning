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
        stack<TreeNode*> st;
        TreeNode *p = NULL, *tmp = NULL;
        vector<int> ret;
        if (!root) return ret;
        st.push(root);
        while (!st.empty()) {
            p = st.top();
            while (p->left) {
                st.push(p->left);
                tmp = p;
                p = p->left;
                tmp->next = NULL;
            }

            p = st.top();
            p.pop();
            ret.push_back(p->val);
            p.push()
        }
    }
};
