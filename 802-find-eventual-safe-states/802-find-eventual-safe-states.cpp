class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>indegree(n,0);
        queue<int>q;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            indegree[i]=graph[i].size();
            if(indegree[i]==0)
            {
                q.push(i);
                ans.push_back(i);
            }
        }
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                adj[graph[i][j]].push_back(i);
            }
        }
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto it:adj[node])
            {
                if(--indegree[it]==0)
                {
                    q.push(it);
                    ans.push_back(it);
                }
            }
        }
        sort(begin(ans),end(ans));
        return ans;
    }
};