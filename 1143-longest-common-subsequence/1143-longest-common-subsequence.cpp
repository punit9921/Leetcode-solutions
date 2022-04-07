class Solution {
public:
    vector<vector<int>>dp;
   
        
    int longestCommonSubsequence(string text1, string text2) {
       dp=vector<vector<int>>(text1.size()+1,vector<int>(text2.size()+1,-1));
        int n=text1.size(),m=text2.size();
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0 or j==0)
                    dp[i][j]=0;
                else if(text1[i-1]==text2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};