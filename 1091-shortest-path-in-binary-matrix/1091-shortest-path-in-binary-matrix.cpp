class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int dis=0;
        int dx[]={-1,-1,-1,1,1,1,0,0};
        int dy[]={-1,0,1,-1,0,1,-1,1};
        queue<pair<int,int>>q;
        if(grid[0][0]==1 or grid[n-1][m-1]==1)
            return -1;
        q.push({0,0});
        grid[0][0]=1;
        while(!q.empty())
        {
            int sz=q.size();
            dis++;
            while(sz--)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                if(x==n-1 and y==m-1)
                    return dis;
                for(int i=0;i<8;i++)
                {
                    int nx=x+dx[i];
                    int ny=y+dy[i];
                    if(nx>=0 and nx<n and ny>=0 and ny<n and grid[nx][ny]==0)
                    {
                        q.push({nx,ny});
                        grid[nx][ny]=1;
                    }
                }
            }
        }
        return -1;
        
    }
};