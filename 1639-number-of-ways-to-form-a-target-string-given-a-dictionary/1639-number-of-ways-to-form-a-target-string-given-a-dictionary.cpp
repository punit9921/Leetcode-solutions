class Solution {
public:
    vector<vector<long long>>freq;
    int n;
    int dp[1001][1001];
    const int mod=1e9+7;
    int solve(string &target,int i,int j)
    {
        if(j>=target.size())
            return 1;
        if(i>=n)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
      long long  int ans=0;
        ans=solve(target,i+1,j)%mod;
        int ind=target[j]-'a';
        ans=(ans+(freq[ind][i]*(solve(target,i+1,j+1))%mod)%mod)%mod;
        return dp[i][j]=ans;
            
    }
    int numWays(vector<string>& words, string target) {
        n=words[0].size();
        freq=vector<vector<long long>>(26,vector<long long>(n,0));
        for(auto it:words)
        {
            for(int i=0;i<it.size();i++)
            {
                freq[it[i]-'a'][i]++;
            }
        }
        memset(dp,-1,sizeof(dp));
        return solve(target,0,0);
    }
};