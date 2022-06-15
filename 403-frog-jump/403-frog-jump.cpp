class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        dp[0][1]=1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                int d=stones[i]-stones[j];
                if(d>0 and d<n and dp[j][d])
                {
                    if(i==n-1)
                        return true;
                    dp[i][d]=1;
                    if(d+1<n)
                        dp[i][d+1]=1;
                    if(d-1<n)
                        dp[i][d-1]=1;
                }
            }
        }
        return dp[n-1][n-1];
    }
};