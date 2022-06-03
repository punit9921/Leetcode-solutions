class Solution {
public:
    const int mod=1e9+7;
    int maxProductPath(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
       long long int dp[n][m],dp1[n][m];
        dp[0][0]=dp1[0][0]=grid[0][0];
        for(int i=1;i<n;i++)
            dp1[i][0]=dp[i][0]=(dp[i-1][0]*grid[i][0]);
        for(int i=1;i<m;i++)
            dp1[0][i]=dp[0][i]=(dp[0][i-1]*grid[0][i]);
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(grid[i][j]<0)
                {
                    dp[i][j]=(min(dp1[i-1][j],dp1[i][j-1])*grid[i][j]);
                    dp1[i][j]=(max(dp[i-1][j],dp[i][j-1])*grid[i][j]);
                }
                else
                {
                    dp[i][j]=(max(dp[i-1][j],dp[i][j-1])*grid[i][j]);
                    dp1[i][j]=(min(dp1[i-1][j],dp1[i][j-1])*grid[i][j]);
                }
            }
        }
        int ans=dp[n-1][m-1]%mod;
        if(ans<0)
            return -1;
        return ans;
    }
};