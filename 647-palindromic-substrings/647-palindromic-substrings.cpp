class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        if(n<2)
            return n;
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        int ans=0;
        for(int i=1;i<=n;i++)
            dp[i][i]=1;
        for(int i=0;i<n;i++)
        {
            if(s[i]==s[i+1])
            {
                ans++;
                dp[i][i+1]=1;
            }
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j+i<n;j++)
            {
                int k=i+j;
                if(s[j]==s[k] and dp[j+1][k-1])
                {
                    ans++;
                    dp[j][k]=1;
                }
            }
        }
        return ans+n ;
    }
};