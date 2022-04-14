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
#include<bits/stdc++.h>
class Solution {
public:
   
    int widthOfBinaryTree(TreeNode* root) {
    queue<pair<TreeNode*,long>>q;
        if(root==NULL)
            return 0;
        q.push({root,0});
        int ans=0;
        while(!q.empty())
        {
            int n=q.size();
            long min_ind=q.front().second;
            int l=0,f=0;
            for(int i=0;i<n;i++)
            {
                auto node=q.front().first;
                long ind=q.front().second;
                q.pop();
                long diff=ind-min_ind;
                if(i==0)
                    f=diff;
                if(i==n-1)
                    l=diff;
                if(node->left)
                    q.push({node->left,2*diff+1});
                if(node->right)
                    q.push({node->right,2*diff+2});
            }
            ans=max(ans,l-f+1);
        }
        return ans;
        
    }
};