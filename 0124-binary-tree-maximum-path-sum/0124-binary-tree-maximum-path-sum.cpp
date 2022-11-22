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
    int sum=INT_MIN;
    int solve(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        
        int lsum=max(0,solve(root->left));
        int rsum=max(0,solve(root->right));
        int csum=lsum+rsum+root->val;
        sum=max(sum,csum);
        return root->val+max(lsum,rsum);
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return sum;
    }
};