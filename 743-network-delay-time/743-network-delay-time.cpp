class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dis(n+1,INT_MAX);
        dis[k]=0;
        for(int i=1;i<=n-1;i++)
        {
            for(auto it:times)
            {
                int src=it[0];
                int des=it[1];
                int wt=it[2];
                if(dis[src]!=INT_MAX and dis[src]+wt<dis[des] )
                    dis[des]=dis[src]+wt;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
            ans=max(ans,dis[i]);
        if(ans==INT_MAX)
            return -1;
        else
            return ans;
    }
};