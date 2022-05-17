class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int dx[]={-1,1,0,-1,1,0,1,-1};
        int dy[]={-1,-1,-1,1,1,1,0,0};
        if(grid[0][0]==1)
            return -1;
        queue<pair<int,int>>q;
        q.push({0,0});
        grid[0][0]=1;
        int ans=0;
        while(!q.empty())
        {
            int sz=q.size();
            ans++;
            while(sz--)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                if(x==n-1 and y==m-1)
                    return ans;
                for(int i=0;i<8;i++)
                {
                    int nx=x+dx[i];
                    int ny=y+dy[i];
                    if(nx>=0 and ny>=0 and nx<n and ny<m and grid[nx][ny]==0)
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