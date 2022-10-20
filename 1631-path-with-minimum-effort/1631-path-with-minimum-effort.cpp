class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        priority_queue<vector<int>,vector<vector<int>>,greater<>>pq;
        pq.push({0,0,0});
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=0;
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        
        while(!pq.empty())
        {
            auto temp=pq.top();
            pq.pop();
            int dis=temp[0];
            int x=temp[1];
            int y=temp[2];
            if(x==n-1 and y==m-1)
                return dis;
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx<0 or nx>=n or ny<0 or ny>=m)
                    continue;
                int new_dis=max(dis,abs(heights[nx][ny]-heights[x][y]));
                if(new_dis<dist[nx][ny])
                {
                    dist[nx][ny]=new_dis;
                    pq.push({new_dis,nx,ny});
                }
            }
        }
        return -1;
    }
};