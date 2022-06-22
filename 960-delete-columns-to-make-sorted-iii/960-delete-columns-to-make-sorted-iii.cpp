class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size();
        int m=strs[0].size();
        int ans=m-1;
        int k;
        vector<int>dp(m,1);
        for(int i=1;i<m;i++)
        {
            for(int j=0;j<i;j++)
            {
                for(k=0;k<n;k++)
                {
                    if(strs[k][i]<strs[k][j])
                        break;
                }
                if(k==n and dp[i]<dp[j]+1)
                    dp[i]=dp[j]+1;
            }
            ans=min(ans,m-dp[i]);
        }
        return ans;
    }
};