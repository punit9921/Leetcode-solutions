class Solution {
public:
    string longestPalindrome(string s) {
        string ans="";
        int n=s.size();
        bool dp[n][n];
        memset(dp,false,sizeof(dp));
        if(n==0)
            return ans;
        for(int i=0;i<n;i++)
        {
            dp[i][i]=true;
        }
        ans+=s[0];
        int start=0;
        int mxlen=1;
        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
            {
                dp[i][i+1]=true;
                start=i;
                mxlen=2;
            }
        }
        for(int k=3;k<=n;k++)
        {
            for(int i=0;i<n-k+1;i++)
            {
                int j=i+k-1;
                if(s[i]==s[j] and dp[i+1][j-1])
                {
                    dp[i][j]=true;
                    if(k>mxlen)
                    {
                        mxlen=k;
                        start=i;
                    }
                }
            }
        }
        return s.substr(start,mxlen);
    }
};