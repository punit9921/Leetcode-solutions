class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<bool>mst(n,false);
        int min_cost=0;
        int remaining=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        pq.push({0,0});
        while(remaining<n)
        {
            int wt=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(mst[node])
                continue;
            mst[node]=true;
            min_cost+=wt;
            remaining++;
            for(int i=0;i<n;i++)
            {   
                if(!mst[i])
                {int next_wt=abs(points[node][0]-points[i][0])+abs(points[node][1]-points[i][1]);
                 pq.push({next_wt,i});
                }
            }
        }
        return min_cost;
    }
};