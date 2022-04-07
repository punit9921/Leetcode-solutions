class Solution {
public:
    int cnt=0;
    void dfs(int ind,int n,vector<int>&vis)
    {
        if(ind>n)
            cnt++;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i] and (ind%i==0 or i%ind==0))
            {
                vis[i]=1;
                dfs(ind+1,n,vis);
                vis[i]=0;
            }
        }
    }
    int countArrangement(int n) {
        vector<int>vis(n+1,0);
        dfs(1,n,vis);
        return cnt;
    }
};