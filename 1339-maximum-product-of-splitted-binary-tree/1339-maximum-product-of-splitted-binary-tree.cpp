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
   long long int totalsum;
   long long int res;
    const int mod=1e9+7;
    
   void findsum(TreeNode* root)
    {
        if(root==NULL)
            return ;
        totalsum+=root->val;
        findsum(root->left);
       findsum(root->right);
    }
    int findans(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int lsum=findans(root->left);
        int rsum=findans(root->right);
        res=max({res,(totalsum-lsum)*lsum,(totalsum-rsum)*rsum});
        return lsum+rsum+root->val;
    }
    int maxProduct(TreeNode* root) {
        totalsum=0;
        res=0;
        findsum(root);
        findans(root);
        return res%mod;
    }
};