class Solution {
public:
    void dfs(int node,vector<vector<int>>&adj,vector<bool>&vis)
    {
        vis[node]=true;
        for(auto it:adj[node])
        {
            if(!vis[it])
                dfs(it,adj,vis);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)
            return -1;
        vector<vector<int>>adj(n);
        for(int i=0;i<connections.size();i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        vector<bool>vis(n,false);
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                cnt++;
                dfs(i,adj,vis);
            }
        }
        return cnt-1;
    }
};