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
    int cnt;
    void solve(TreeNode* root,int val)
    {
        if(root==NULL)
            return ;
        if(root->val>=val)
        {
            val=root->val;
            cnt++;
        }
        solve(root->left,val);
        solve(root->right,val);
        return;
        
    }
    int goodNodes(TreeNode* root) {
        cnt=0;
        solve(root,root->val);
        return cnt;
    }
};