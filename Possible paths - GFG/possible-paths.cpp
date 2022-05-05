// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
  vector<int>adj[51];
  long long int dp[51][51];
  const int mod=1e9+7;
  long long int solve(int node,int dest,int k)
  {
      if(k==0)
      {
          if(node==dest)
          return 1LL;
          return 0;
      }
      if(dp[node][k]!=-1)
      return dp[node][k];
      
      long long int cnt=0;
      for(auto it:adj[node])
      {
          cnt=(cnt+1LL*solve(it,dest,k-1))%mod;
      }
      return dp[node][k]=cnt;
  }
	int MinimumWalk(vector<vector<int>>&graph, int u, int v, int k){
	    // Code here
	    int n=graph.size();
	    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(graph[i][j] == 1){
                adj[i].push_back(j);
            }
        }
    }
	    memset(dp,-1,sizeof(dp));
	    return solve(u,v,k);
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>graph(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> graph[i][j];
			}
		}
		int u, v, k;
		cin >> u >> v >> k;
		Solution obj;
		int ans = obj.MinimumWalk(graph, u, v, k);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends