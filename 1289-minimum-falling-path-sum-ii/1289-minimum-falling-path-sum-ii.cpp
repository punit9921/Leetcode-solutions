class Solution {
public:
    int n,m;
    int dp[202][202];
    int solve(vector<vector<int>>&grid,int i,int j)
    {
        if(i==n)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
       
        int res=INT_MAX;
        for(int k=0;k<m;k++)
        {
            if(k==j)
                continue;
            int ans=grid[i][j]+solve(grid,i+1,k);
            res=min(res,ans);
        }
        return dp[i][j]=res;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        n=grid.size();
        m=grid[0].size();
        if(n==1)
            return grid[0][0];
        int ans=INT_MAX;
        for(int i=0;i<m;i++)
        {
            ans=min(ans,solve(grid,0,i));
        }
        return ans;
    }
};