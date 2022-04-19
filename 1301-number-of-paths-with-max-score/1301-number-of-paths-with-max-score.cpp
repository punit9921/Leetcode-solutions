class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n=board.size();
        int m=board[0].size();
        int mod = 1000000007;
        if(n==0)
            return {};
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(2)));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(i==n-1 and j==m-1)
                {
                    dp[i][j]={0,1};
                }
                else if(board[i][j]=='X')
                {
                    dp[i][j]={INT_MIN,0};
                }
                else
                {
                    int val=INT_MIN,cnt=0;
                    if(j+1<m and dp[i][j+1][0]!=INT_MIN)
                    {
                        val=dp[i][j+1][0];
                        cnt=dp[i][j+1][1];
                    }
                    if(i+1<n and dp[i+1][j][0]!=INT_MIN and val<=dp[i+1][j][0])
                    {
                        if(val<dp[i+1][j][0])
                        {
                            val=dp[i+1][j][0];
                            cnt=dp[i+1][j][1];
                        }
                        else
                        {
                            cnt=(cnt+dp[i+1][j][1])%mod;
                        }
                    }
                    if(i+1<n and j+1<m and dp[i+1][j+1][0]!=INT_MIN and val<=dp[i+1][j+1][0])
                    {
                        if(val<dp[i+1][j+1][0])
                        {
                            val=dp[i+1][j+1][0];
                            cnt=dp[i+1][j+1][1];
                        }
                        else
                        {
                            cnt=(cnt+dp[i+1][j+1][1])%mod;
                        }
                    }
                    if(val==INT_MIN)
                        dp[i][j]={INT_MIN,0};
                    else if(i==0 and j==0)
                        dp[i][j]={val,cnt%mod};
                    else 
                        dp[i][j]={val+(board[i][j]-'0'),cnt%mod};
                        
                }
            }
        }
        if(dp[0][0][0]==INT_MIN)
            return {0,0};
        else
            return dp[0][0];
    }
};