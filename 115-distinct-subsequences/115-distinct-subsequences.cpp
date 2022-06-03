class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<unsigned long long int>>dp(n+1,vector<unsigned long long int>(m+1,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++)
            dp[i][0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(j>i)
                    continue;
                dp[i][j]=dp[i-1][j];
                if(s[i-1]==t[j-1])
                    dp[i][j]+=dp[i-1][j-1];
            }
        }
        return dp[n][m];
    }
};