class Solution {
public:
    const int mod=1e9+7;
    int solve(unordered_map<int,vector<pair<int,int>>>&mp,int node,vector<int>&dis,vector<int>&dp)
    {
        if(node==1)
            return 1;
        if(dp[node]!=-1)
            return dp[node];
        int sum=0;
        for(auto it:mp[node])
        {
            int wt=dis[node];
            int val=dis[it.first];
            if(val>wt)
            {
                sum=(sum%mod+solve(mp,it.first,dis,dp)%mod)%mod;
            }
        }
        return dp[node]=sum%mod;
    }
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<pair<int,int>>>grp;
        for(auto it:edges)
        {
            grp[it[0]].push_back({it[1],it[2]});
            grp[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        vector<int>dis(n+1,INT_MAX);
        pq.push({0,n});
        dis[n]=0;
        while(!pq.empty())
        {
            auto temp=pq.top();
            pq.pop();
            int node=temp.second;
            for(auto it:grp[node])
            {
                if(dis[it.first]>it.second+dis[node])
                {
                    dis[it.first]=it.second+dis[node];
                    pq.push({dis[it.first],it.first});
                }
            }
        }
        vector<int>dp(n+1,-1);
        return solve(grp,n,dis,dp);
    }
};