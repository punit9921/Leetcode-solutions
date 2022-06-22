class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
       int n=scores.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)
            v.push_back({ages[i],scores[i]});
        sort(begin(v),end(v));
        
        int dp[n];
        for(int i=0;i<n;i++)
            dp[i]=v[i].second;
        int ans=INT_MIN;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(v[i].second>=v[j].second and dp[i]<dp[j]+v[i].second)
                {
                    dp[i]=dp[j]+v[i].second;
                    
                }
               
            }
            
        }
        for(int i=0;i<n;i++)
            ans=max(ans,dp[i]);
        return ans;
    }
};