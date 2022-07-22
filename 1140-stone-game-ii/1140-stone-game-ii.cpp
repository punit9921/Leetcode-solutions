class Solution {
public:
    int dp[101][101];
    int solve(int i,int m,vector<int>&piles)
    {
        if(i==piles.size())
            return 0;
        if(dp[i][m]!=-1)
            return dp[i][m];
        int ans=INT_MIN;
        int sum=0;
        for(int j=i;j<piles.size() and j-i+1<=2*m;j++)
        {
            sum+=piles[j];
            ans=max(ans,sum-solve(j+1,max(m,j-i+1),piles));
        }
        return dp[i][m]=ans;
    }
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        memset(dp,-1,sizeof(dp));
        int sum=0;
        for(auto it:piles)
            sum+=it;
        return (sum+solve(0,1,piles))/2;
    }
};