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
   vector<TreeNode*>helper(int n)
   {
       vector<TreeNode*>res;
       if(n==1)
       {
           TreeNode* root=new TreeNode(0);
           res.push_back(root);
           return res;
       }
       for(int i=1;i<n;i+=2)
       {
           vector<TreeNode*>ltree=helper(i);
           vector<TreeNode*>rtree=helper(n-i-1);
           for(auto l:ltree)
           {
               for(auto r:rtree)
               {
                   TreeNode* root=new TreeNode(0);
                   root->left=l;
                   root->right=r;
                   res.push_back(root);
               }
           }
           
       }
       return res;
   }
    vector<TreeNode*> allPossibleFBT(int n) {
        return helper(n);
    }
};