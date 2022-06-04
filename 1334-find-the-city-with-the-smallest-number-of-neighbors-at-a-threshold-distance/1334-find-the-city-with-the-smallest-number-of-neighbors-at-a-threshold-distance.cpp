class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<pair<int,int>>adj[n+1];
        for(auto it:edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        map<int,int>cities;
        for(int i=0;i<n;i++)
        {
            vector<int>dis(n,INT_MAX);
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
            dis[i]=0;
            pq.push({0,i});
            while(!pq.empty())
            {
                int wt=pq.top().first;
                int node=pq.top().second;
                pq.pop();
                for(auto it:adj[node])
                {
                    if(dis[it.first]>it.second+dis[node])
                    {
                        dis[it.first]=it.second+dis[node];
                        pq.push({dis[it.first],it.first});
                    }
                }
               
            }
             for(auto it:dis)
                {
                    
                    if(it!=0 and it<=distanceThreshold)
                    {
                        cities[i]++;
                      //  cout<<it<<" ";
                    }
                }
        }
        int mini=cities[0];
        int ans=0;
        for(int i=1;i<n;i++)
        {
            if(cities[i]<=mini)
            {
                mini=cities[i];
                ans=i;   
            }
        }
        return ans;
    }
};