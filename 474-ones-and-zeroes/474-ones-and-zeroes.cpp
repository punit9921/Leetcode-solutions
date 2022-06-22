class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1));
        for(auto &str:strs)
        {
        int ones=0,zeroes=0;
            for(auto it:str)
            {
                if(it=='0')
                    zeroes++;
                else
                    ones++;
            }
        for(int i=m;i>=0;i--)
        {
            for(int j=n;j>=0;j--)
            {
                if(i>=zeroes and j>=ones)
                dp[i][j]=max(dp[i][j],dp[i-zeroes][j-ones]+1);
            }
        }
        }
        return dp[m][n];
    }
};