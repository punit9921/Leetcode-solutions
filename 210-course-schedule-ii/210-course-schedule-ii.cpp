class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>>graph(numCourses);
    vector<int>indegree(numCourses);
        vector<int>res;
        int cnt=0;
        for(auto it:prerequisites)
        {
            int u=it[0],v=it[1];
            graph[v].push_back(u);
            indegree[u]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            cnt++;
            res.push_back(node);
            for(auto it:graph[node])
            {
                if(--indegree[it]==0)
                    q.push(it);
            }
            
            
        }
        if(cnt==numCourses)
            return res;
        return {};
            
    }
};