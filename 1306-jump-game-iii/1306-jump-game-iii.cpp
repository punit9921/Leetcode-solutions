class Solution {
public:
    int n;
    bool solve(vector<int>&v,int i,vector<bool>&vis)
    {
        if(i<0 or i>=n or vis[i])
            return false;
        if(v[i]==0)
            return true;
        vis[i]=true;
        return solve(v,i+v[i],vis) or solve(v,i-v[i],vis);
    }
    bool canReach(vector<int>& arr, int start) {
        n=arr.size();
        vector<bool>vis(n,false);
        return solve(arr,start,vis);
    }
};