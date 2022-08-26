/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isbst(TreeNode* root,long minval,long maxval)
    {
        if(!root)
            return true;
        if(root->val<=minval or root->val>=maxval)
            return false;
        return isbst(root->left,minval,root->val) and isbst(root->right,root->val,maxval);
    }
    bool isValidBST(TreeNode* root) {
        return isbst(root,LONG_MIN,LONG_MAX);
    }
};