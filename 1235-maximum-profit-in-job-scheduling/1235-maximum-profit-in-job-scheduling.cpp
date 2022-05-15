class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        return a[1]<b[1];
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        vector<vector<int>>v(n);
        int dp[n];
        for(int i=0;i<n;i++)
        {
            v[i]={startTime[i],endTime[i],profit[i]};
        }
        sort(v.begin(),v.end(),cmp);
        dp[0]=v[0][2];
        for(int i=1;i<n;i++)
        {
            int op=0;
            for(int j=i-1;j>=0;j--)
            {
                if(v[j][1]<=v[i][0])
                {
                    op=dp[j];
                    break;
                }
            }
            dp[i]=max(dp[i-1],op+v[i][2]);
        }
        return dp[n-1];
    }
};