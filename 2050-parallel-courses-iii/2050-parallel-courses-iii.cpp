class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int>indegree(n,0);
        vector<vector<int>>g(n);
        for(auto it:relations)
        {
            int u=it[0]-1;
            int v=it[1]-1;
            g[u].push_back(v);
            indegree[v]++;
        }
        queue<int>q;
        vector<int>dis(n,0);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
                dis[i]=time[i];
                ans=max(ans,dis[i]);
            }
        }
       
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto it:g[node])
            {
                dis[it]=max(dis[it],dis[node]+time[it]);
                ans=max(ans,dis[it]);
                if(--indegree[it]==0)
                    q.push(it);
                    
            }
        }
        return ans;
    }
};