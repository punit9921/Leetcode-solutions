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
    int cnt=0;
    pair<int,int>dfs(TreeNode* root)
    {
        if(root==NULL)
            return {0,0};
        auto l=dfs(root->left);;
        auto r=dfs(root->right);
        int sum=l.first+r.first+root->val;
        int n=l.second+r.second+1;
        if((sum/n)==root->val)
            cnt++;
        return {sum,n};
    }
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return cnt;
    }
};