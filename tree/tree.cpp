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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1 && !t2)
            return NULL;
        TreeNode* root  = new TreeNode(0);
        if(t1 && !t2) {
        	root->val = t1->val;
        	root->left = mergeTrees(t1->left, NULL);
        	root->right = mergeTrees(t1->right, NULL);
        }
        if(!t1 && t2) {
        	root->val = t2->val;
        	root->left = mergeTrees(NULL, t2->left);
        	root->right = mergeTrees(NULL, t2->right);
        }

        if(t1 && t2) {
        	root->val = t1->val + t2->val;
        	root->left = mergeTrees(t1->left, t2->left);
        	root->right = mergeTrees(t1->right, t2->right);
        }
        return root;
    }
};

int treeHight(TreeNode *root) {
	if(!root) return 0;

	int left_height = treeHight(root->left);
	int right_height = treeHight(root->right);

	return max(left_height, right_height) + 1;
}




static int lookup(struct node* node, int target) {
// 1. Base case == empty tree
// in that case, the target is not found so return false
    if (node == NULL) {
        return(false);
}
else {
// 2. see if found here
if (target == node->data) return(true);
else {
// 3. otherwise recur down the correct subtree
    if (target < node->data) return(lookup(node->left, target));
    else return(lookup(node->right, target));
    }
    }
}



struct node* NewNode(int data) {
struct node* node = new(struct node);
// "new" is like "malloc"
node->data = data;
node->left = NULL;
node->right = NULL;
return(node);
}

 void insert(struct node* node, int data) {

// 1. If the tree is empty, return a new, single node
    if (node == NULL) {
        return(newNode(data));
    }
    else {
// 2. Otherwise, recur down the tree
        if (data <= node->data) node->left = insert(node->left, data);
        else node->right = insert(node->right, data);
    }
}

