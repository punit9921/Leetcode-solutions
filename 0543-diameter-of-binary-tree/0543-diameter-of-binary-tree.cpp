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
    int solve(TreeNode* root,int *height)
    {
        if(!root)
            return 0;
        int lh=0,rh=0;
        int ld=solve(root->left,&lh);
        int rd=solve(root->right,&rh);
        int curr=lh+rh;
        *height=max(lh,rh)+1;
        return max({curr,ld,rd});
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        int height=0;
        return solve(root,&height);
    }
};