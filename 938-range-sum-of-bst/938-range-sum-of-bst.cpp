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
    void calculate(TreeNode *root,int low,int high,int *sum)
    {
       if(root==NULL)
            return ;
         if(low<=root->val and high>=root->val)
        {
           *sum=*sum+root->val;
        }
        
        if(root->val>low)
           calculate(root->left,low,high,sum);
       
        if(high>root->val)
            calculate(root->right,low,high,sum);
        
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
      
        if(root==NULL)
            return 0;
        int sum=0;
     calculate(root,low,high,&sum);
        return sum;
    }
};