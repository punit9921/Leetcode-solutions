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
     TreeNode *lcafunc(TreeNode *root,int start,int end){
        if(!root) return nullptr;
        if(root->val==start or root->val==end) return root;
        TreeNode *l=lcafunc(root->left,start,end);
        TreeNode *r=lcafunc(root->right,start,end);
        if(l && r) return root;
        return l?l:r;
    }
    bool makepath(TreeNode *root,int value,string &s){
        if(!root) return false ;
        if(root->val==value) {
            
            return true;
        }
        s+="L";
        if(makepath(root->left,value,s))
            return true;
        s.pop_back();
        s+="R";
       if( makepath(root->right,value,s))
           return true;
        s.pop_back();
        return false;
    }
    string getDirections(TreeNode* root, int start, int end) {
           TreeNode *lca=lcafunc(root,start,end);
        
           string s1,s2;
           makepath(lca,start,s1);
        cout<<s1;
           makepath(lca,end,s2);
         
        for(auto &it:s1)
            it='U';
            
        return s1+s2;
    }
};