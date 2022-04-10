class Solution {
public:
  double dfs(int node,vector<vector<int>>&adj,vector<bool>&vis,int target,int t)
    {
        vis[node]=true;
      if(t==0)
      {
          if(node==target)
              return 1.0;
          return 0.0;
      }
      int cnt=0;
      double ans;
      double subans=0.0;
      for(auto it:adj[node])
      {
          if(vis[it]==false)
          {
              cnt++;
              subans+=dfs(it,adj,vis,target,t-1);
          }
      }
      if(cnt>0)
      {
          ans=1.0/(cnt*1.0);
          ans=ans*subans;
      }
      else
      {
          if(node==target)
          {
              ans=1.0;
              
          }
          else
              ans=0.0;
      }
      return ans;
    }
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>>adj(n+1);
        for(auto edge:edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
      
        vector<bool>vis(n+1,false);
      
       return dfs(1,adj,vis,target,t);
       
    }
};