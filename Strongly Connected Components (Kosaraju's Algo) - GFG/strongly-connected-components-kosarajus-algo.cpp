// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	stack<int>st;
void dfs(int node,vector<int>adj[],vector<int>&vis)
{
    vis[node]=1;
    for(auto it:adj[node])
    {
        if(!vis[it])
        dfs(it,adj,vis);
    }
    st.push(node);
}
void dfs1(int node,vector<vector<int>>&g,vector<int>&vis)
{
    vis[node]=1;
    for(auto it:g[node])
    {
        if(!vis[it])
        dfs1(it,g,vis);
    }
}
    int kosaraju(int n, vector<int> adj[])
    {
        //code here
        
    vector<int>vis(n,0);
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        dfs(i,adj,vis);
    }
  vector<vector<int>>transpose(n);
    for(int i=0;i<n;i++)
    {
        vis[i]=0;
        for(auto it:adj[i])
        {
            transpose[it].push_back(i);
        }
    }
    int cnt=0;
    while(!st.empty())
    {
        int node=st.top();
        st.pop();
        if(!vis[node])
        {
            cnt++;
            dfs1(node,transpose,vis);
        }
    }
    return cnt;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends