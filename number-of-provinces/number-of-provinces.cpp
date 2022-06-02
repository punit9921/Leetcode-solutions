class Solution {
public:
    void dfs(vector<bool>&vis, vector<vector<int>>&graph,int ind)
    {
        vis[ind]=true;
        for(int i=0;i<graph.size();i++)
        {
            if(graph[ind][i]==1 and vis[i]==false)
                dfs(vis,graph,i);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool>vis(n,false);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==false)
            {
             ans++;
                dfs(vis,isConnected,i);
            }
        }
        return ans;
    }
};