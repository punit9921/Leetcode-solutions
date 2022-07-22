class Solution {
public:
    double dp[101][101];
    double solve(vector<int>&nums,int ind,int k)
    {
        if(ind>=nums.size() or k<0)
            return 0;
        if(k==0)
            return INT_MIN/2;
        if(dp[ind][k]!=0)
            return dp[ind][k];
        double ans=0;
        double sum=0;
        for(int j=ind;j<nums.size();j++)
        {
            sum+=nums[j];
            ans=max(ans,sum/(j-ind+1)+solve(nums,j+1,k-1));
        }
        return dp[ind][k]=ans;
            
    }
    double largestSumOfAverages(vector<int>& nums, int k) {
        memset(dp,0,sizeof(dp));
        return solve(nums,0,k);
    }
};