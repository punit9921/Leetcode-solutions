class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size();
        int sum=0;
        for(auto stone:stones)
            sum+=stone;
       bool dp[n+1][sum+1];
        for(int i=0;i<=n;i++)
            dp[i][0]=true;
        for(int j=1;j<=sum;j++)
            dp[0][j]=false;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
              
                    
               if(stones[i-1]<=j)
                    dp[i][j]=(dp[i-1][j] || dp[i-1][j-stones[i-1]]);
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        int diff=INT_MAX;
        for(int i=sum/2;i>=0;i--)
        {
            if(dp[n][i]==true)
            {
                diff=min(diff,sum-2*i);
            }
        }
        return diff;
    }
};
