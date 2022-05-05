// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
bool isbi(int node,int color[],int n,vector<int>adj[])
{
    if(color[node]==-1)
    color[node]=1;
    for(auto it:adj[node])
    {
        if(color[it]==-1)
        {
            color[it]=1-color[node];
            if(!isbi(it,color,n,adj))
            return false;
        }
        else if(color[it]==color[node])
        return false;
    }
    return true;
}
	bool isBipartite(int n, vector<int>adj[]){
	    // Code here
	    int color[n];
	    memset(color,-1,sizeof(color));
	    for(int i=0;i<n;i++)
	    {
	        if(color[i]==-1)
	        {
	            if(!isbi(i,color,n,adj))
	            return false;
	        }
	    }
	    return true;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends