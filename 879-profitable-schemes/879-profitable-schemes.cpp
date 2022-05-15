class Solution {
public:
    int dp[200][200][200];
    const int mod=1e9+7;
    int solve(int n,int p,int g,vector<int>&group,vector<int>&profit)
    {
        if(n==0)
        {
            return p<=0;
        }
        if(p<0) p=0;
        if(dp[n][p][g]!=-1)
            return dp[n][p][g];
        int cnt=solve(n-1,p,g,group,profit)%mod;
        if(group[n-1]<=g)
            cnt=(cnt+solve(n-1,p-profit[n-1],g-group[n-1],group,profit))%mod;
        return dp[n][p][g]=cnt;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp,-1,sizeof(dp));
        int sz=group.size();
        return solve(sz,minProfit,n,group,profit);
    }
};