class Solution {
public:
    const int mod=1e9+7;
    int dp[31][1001];
    Solution(){
        memset(dp,-1,sizeof(dp));
    }
    int help(int dno,int &tdice,int &tf,int target){
       
        if(target==0 and dno==tdice) {
            return 1;
        }
         if(target<0 or dno>tdice) return 0;
        if(dp[dno][target]!=-1) return dp[dno][target];
        int ans=0;
        for(int i=1;i<=tf;i++){
            ans=(ans%mod+help(dno+1,tdice,tf,target-i)%mod)%mod;
            
        }
        return dp[dno][target]=ans;
    }
    int numRollsToTarget(int n, int k, int target) {
       return help(0,n,k,target);
       
    }
};