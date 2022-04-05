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
    int max_freq;
    unordered_map<int,int>freq;
    unordered_map<int,vector<int>>mp;
    int dfs(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        root->val+=dfs(root->left);
        root->val+=dfs(root->right);
        freq[root->val]++;
        if(freq[root->val]>=max_freq)
        {
            max_freq=freq[root->val];
            mp[max_freq].push_back(root->val);
        }
        return root->val;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        return mp[max_freq];
    }
};