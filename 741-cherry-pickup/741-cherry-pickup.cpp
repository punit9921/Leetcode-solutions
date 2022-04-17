class Solution {
public:
    int dp[101][101][101];
    int solve(int r1,int c1,int c2,int n,vector<vector<int>>&grid)
    {
        int r2=r1+c1-c2;
        if(r1>=n or r2>=n or c1>=n or c2>=n or grid[r1][c1]==-1 or grid[r2][c2]==-1)
            return INT_MIN;
        if(dp[r1][c1][c2]!=-1)
            return dp[r1][c1][c2];
        if(r1==n-1 and c1==n-1)
            return grid[r1][c1];
        int ans=grid[r1][c1];
        if(r1!=r2)
            ans+=grid[r2][c2];
        int temp = max({solve(r1,c1+1,c2+1,n,grid),solve(r1+1,c1,c2,n,grid),
                       solve(r1,c1+1,c2,n,grid),solve(r1+1,c1,c2+1,n,grid)});
        ans+=temp;
        return dp[r1][c1][c2]=ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        memset(dp,-1,sizeof(dp));
        return max(0,solve(0,0,0,n,grid));
        
    }
};