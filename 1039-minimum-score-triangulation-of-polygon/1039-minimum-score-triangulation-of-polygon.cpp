class Solution {
public:
    int dp[201][201];
    int solve(vector<int>&arr,int i,int j)
    {
        if(j-i==1)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int ans=INT_MAX;
        for(int cut=i+1;cut<j;cut++)
        {
            ans=min(ans,solve(arr,i,cut)+solve(arr,cut,j)+arr[i]*arr[cut]*arr[j]);
        }
        return dp[i][j]=ans;
    }
    int minScoreTriangulation(vector<int>& values) {
        memset(dp,-1,sizeof(dp));
        int n=values.size();
        return solve(values,0,n-1);
    }
};