#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

const int maxn = 1000 + 10;


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
	bool isSubtree_core(TreeNode* s, TreeNode* t){
		if(t == NULL)
			if(s == NULL) return true;
			else return false;
		if(s == NULL) return false;
		if(s->val != t->val)
			return false;
		return isSubtree_core(s->left, t->left) && isSubtree_core(s->right, t->right);
	}
    bool isSubtree(TreeNode* s, TreeNode* t) {
    	if(s == t || t == NULL) return true;
    	if(s == NULL) return false;
    	bool flag = false;
    	if(s->val == t->val)
    		flag = isSubtree_core(s,t);
    	if(flag)
    		return true;
    	return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};


int main()
{
	
	return 0;
}