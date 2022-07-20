class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
        priority_queue<vector<int>,vector<vector<int>>,greater<>>pq;
        pq.push({0,0,0});
        dis[0][0]=0;
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        while(!pq.empty())
        {
            auto temp=pq.top();
            pq.pop();
            int dist=temp[0];
            int x=temp[1];
            int y=temp[2];
            if(x==n-1 and y==m-1)
                return dist;
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx<0 or nx>=n or ny<0 or ny>=m)
                    continue;
                int new_wt=max(dist,abs(heights[nx][ny]-heights[x][y]));
                if(new_wt<dis[nx][ny])
                {
                    dis[nx][ny]=new_wt;
                    pq.push({dis[nx][ny],nx,ny});
                }
            }
        }
        return -1;
    }
};