class Solution {
public:
    vector<vector<int>>dp;
    int solve(int index,vector<vector<int>>&piles,int k)
    {
        if(index>=piles.size() or k==0)
            return 0;
        if(dp[index][k]!=-1)
            return dp[index][k];
        
        //not take
        int ans=solve(index+1,piles,k);
        int sum=0;
        for(int i=0;i<=min(k-1,(int)piles[index].size()-1);i++)
        {
            sum+=piles[index][i];
            ans=max(ans,sum+solve(index+1,piles,k-(i+1)));
        }
        return dp[index][k]=ans;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        dp=vector<vector<int>>(piles.size()+1,vector<int>(k+1,-1));
        return solve(0,piles,k);
    }
};