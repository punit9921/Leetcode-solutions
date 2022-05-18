class Solution {
public:
    vector<vector<int>>vis;
    void dfs(vector<vector<int>>&grid,int x,int y,int &cnt)
    {
        int n=grid.size(),m=grid[0].size();
        if(x<0 or y<0 or x>=n or y>=m or grid[x][y]==0 or vis[x][y])
            return;
        vis[x][y]=1;
        cnt++;
        dfs(grid,x+1,y,cnt);
        dfs(grid,x,y+1,cnt);
        dfs(grid,x-1,y,cnt);
        dfs(grid,x,y-1,cnt);
    }
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<int>rows(n+1,0),col(m+1,0);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    rows[i]++;
                    col[j]++;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j])
                {
                    if(rows[i]>1 or col[j]>1)
                        ans++;
                }
            }
        }
        return ans;
    }
};