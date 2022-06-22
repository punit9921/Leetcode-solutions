class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        string r_str=s;
        reverse(begin(r_str),end(r_str));
        int dp[n+1][n+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0 or j==0)
                    dp[i][j]=0;
                else if(s[i-1]==r_str[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return n-dp[n][n];
    }
};

// mbadm
// mdabm

// leetcode
// edocteel