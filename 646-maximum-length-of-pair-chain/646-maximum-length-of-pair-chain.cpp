class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
       int n=pairs.size();
        int dp[n];
       for(int i=0;i<n;i++)
           dp[i]=1;
        int ans=1;
        sort(begin(pairs),end(pairs));
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(pairs[i][0]>pairs[j][1] and dp[i]<dp[j]+1)
                {
                    dp[i]=dp[j]+1;
                   
                }
                 ans=max(ans,dp[i]);
            }
        }
        return ans;
        
    }
};