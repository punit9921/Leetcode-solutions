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
    bool solve(TreeNode* root,int *height)
    {
        if(!root)
            return true;
        int lh=0,rh=0;
        if(solve(root->left,&lh)==false)
            return false;
        if(solve(root->right,&rh)==false)
            return false;
        *height=1+max(lh,rh);
        if(abs(lh-rh)<=1)
            return true;
        return false;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
            return true;
        int height=0;
        return solve(root,&height);
    }
};