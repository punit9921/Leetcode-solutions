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
    bool isequal(TreeNode* root,TreeNode* root1)
    {
        if(root==NULL or root1==NULL)
            return root==root1;
        return root->val==root1->val and isequal(root->left,root1->left) and isequal(root->right,root1->right);
        
       
    }
    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        return isequal(root,subroot) or(root->left and isSubtree(root->left,subroot)) or (root->right and isSubtree(root->right,subroot));
    }
};