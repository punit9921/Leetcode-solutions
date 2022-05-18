class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int>vis;
        queue<int>q;
        q.push(0);
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            vis.insert(node);
            for(auto it:rooms[node])
            {
                if(vis.find(it)==vis.end())
                {
                    q.push(it);
                }
            }
        }
        return vis.size()==rooms.size();
        
    }
};