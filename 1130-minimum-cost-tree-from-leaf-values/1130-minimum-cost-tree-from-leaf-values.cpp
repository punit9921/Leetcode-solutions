class Solution {
public:
    int dp[101][101];
    int solve(vector<int>&arr,int i,int j)
    {
        if(i==j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        priority_queue<int>pq(arr.begin()+i,arr.begin()+j+1);
        int a=pq.top();
        pq.pop();
        int b=pq.top();
        pq.pop();
        
        int prod=a*b;
        int ans=INT_MAX;
        for(int k=i;k<j;k++)
        {
            ans=min(ans,solve(arr,i,k)+solve(arr,k+1,j));
            
        }
        return dp[i][j]=ans+prod;
    }
    int mctFromLeafValues(vector<int>& arr) {
        int n=arr.size();
        memset(dp,-1,sizeof(dp));
        return solve(arr,0,n-1);
    }
};