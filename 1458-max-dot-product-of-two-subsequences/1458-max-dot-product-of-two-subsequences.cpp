class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<int>&a,vector<int>&b,int i,int j)
    {
        if(i==0 or j==0)
            return 0;
        if(dp[i][j]!=INT_MIN)
            return dp[i][j];
        dp[i][j]=a[i-1]*b[j-1]+max(solve(a,b,i-1,j-1),0);
        if(j>1)
            dp[i][j]=max(solve(a,b,i,j-1),dp[i][j]);
        if(i>1)
            dp[i][j]=max(solve(a,b,i-1,j),dp[i][j]);
        return dp[i][j];
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        dp=vector<vector<int>>(n+1,vector<int>(m+1,INT_MIN));
        return solve(nums1,nums2,n,m);
    }
};