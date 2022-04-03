class Solution {
public:
    
    bool canPartition(vector<int>& nums) {
         int sum=0;
        for(auto it:nums)
        {
            sum+=it;
            
        }
        if(sum%2)
            return false;
        sum=sum/2;
        int dp[nums.size()+1][sum+1];
        for(int i=0;i<=nums.size();i++)
        {
            for(int j=0;j<=sum;j++)
            {
                if(i==0)
                {
                    dp[i][j]=false;
                    continue;
                }
                if(j==0)
                {
                    dp[i][j]=true;
                    continue;
                }
                if(nums[i-1]<=j)
                {
                    dp[i][j]=dp[i-1][j-nums[i-1]] or dp[i-1][j];
                    
                }
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        return dp[nums.size()][sum];
    }
};