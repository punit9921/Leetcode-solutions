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
    struct choice{
        int take;
        int ntake;
    };
    choice dfs(TreeNode* root)
    {
        if(root==NULL)
            return {0,0};
        choice rleft=dfs(root->left);
        choice rright=dfs(root->right);
        int c1=root->val+rleft.ntake+rright.ntake;
        int c2=max(rleft.take,rleft.ntake)+max(rright.take,rright.ntake);
        return choice{c1,c2};
        
    }
    int rob(TreeNode* root) {
    choice r=dfs(root);
        return max(r.take,r.ntake);
    }
};