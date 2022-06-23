class Solution {
public:
   int dp[2005][2005];
    bool ispall(string &s,int i,int j)
    {
     while(i<j)
     {
         if(s[i]!=s[j])
             return false;
         i++,j--;
     }
        return true;
    }
    int solve(string &s,int i,int j)
    {
       if(i>=j)
           return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(ispall(s,i,j))
            return 0;
        int ans = INT_MAX;
        for(int k=i;k<j;k++)
        {
            if(ispall(s,i,k))
            {
                int temp=1+solve(s,k+1,j);
                ans=min(ans,temp);
            }
        }
        return dp[i][j]=ans;
        
    }
    int minCut(string s) {
          int n=s.size();
        memset(dp,-1,sizeof(dp));
        return solve(s,0,n-1);
        
}
};