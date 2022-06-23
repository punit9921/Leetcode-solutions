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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
     
        vector<vector<int>>ans;
        map<int,map<int,multiset<int>>>mp;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty())
        {
            auto temp=q.front();
            q.pop();
            TreeNode* curr=temp.first;
            int x=temp.second.first;
            int y=temp.second.second;
            mp[x][y].insert(curr->val);
            if(curr->left)
                q.push({curr->left,{x-1,y+1}});
            if(curr->right)
                q.push({curr->right,{x+1,y+1}});
        }
        for(auto it:mp)
        {
            vector<int>v;
            for(auto itr:it.second)
            {
                v.insert(v.end(),itr.second.begin(),itr.second.end());
            }
            ans.push_back(v);
        }
        return ans;
    }
};