class Solution {
public:
   int dp[105];
    int decode(string &s,int n,int ind)
    {
        //base case
        if(ind==n)
            return 1;
        if(s[ind]=='0')
            return dp[0]=0;
        if(dp[ind]!=-1)
            return dp[ind];
        int cnt=0;
        if(ind<n-1)
        {
            int num=(s[ind]-'0')*10+(s[ind+1]-'0');
            if(num>=10 and num<=26)
                cnt+=decode(s,n,ind+2);
        }
        return dp[ind]=cnt+decode(s,n,ind+1);
        
    }
       
    int numDecodings(string s) {
       int n=s.size();
         memset(dp,-1,sizeof(dp));
        return decode(s,n,0);
    }
};