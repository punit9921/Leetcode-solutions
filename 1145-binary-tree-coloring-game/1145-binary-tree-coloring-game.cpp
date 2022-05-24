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
    int left,right,val;
   int count(TreeNode* root)
   {
       if(root==NULL)
           return 0;
       int l_count=count(root->left);
       int r_count=count(root->right);
       if(root->val==val)
           left=l_count,right=r_count;
       return l_count+r_count+1;
   }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
       val=x;
        n=count(root);
        int remaining_nodes=n-(1+left+right);
        int mx_val=max({remaining_nodes,left,right});
        return mx_val>n/2;
    }
    
};