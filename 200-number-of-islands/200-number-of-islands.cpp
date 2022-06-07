class Solution {
public:
    bool isvalid(vector<vector<char>>& grid,int x,int y,int rows,int cols)
    {
        if(x<0 or y<0 or x>=rows or y>=cols or grid[x][y]!='1')
            return false;
        return true;
    }
    void solve(vector<vector<int>>& vis,vector<vector<char>>& grid,int x,int y,int rows,int cols)
    {
      
        vis[x][y]=1;
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        for(int i=0;i<4;i++)
        {
            int new_x=x+dx[i];
            int new_y=y+dy[i];
            if(isvalid(grid,new_x,new_y,rows,cols) and !vis[new_x][new_y])
                solve(vis,grid,new_x,new_y,rows,cols);
        }
    
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int rows=grid.size();
        if(rows==0)
            return 0;
        int cols=grid[0].size();
        int n=0;
        vector<vector<int>>vis(rows,vector<int>(cols,0));
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(!vis[i][j] and grid[i][j]=='1')
                {
                    solve(vis,grid,i,j,rows,cols);
                    n++;
                }
            }
        }
        return n;
    }
};