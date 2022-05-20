class Solution {
public:
   void dfs(vector<vector<int>>&grid,int x,int y)
   {
       int dx[]={0,1,0,-1};
       int dy[]={-1,0,1,0};
       if(x<0 or y<0 or x>=grid.size() or y>=grid[0].size() or grid[x][y]==0)
           return ;
       grid[x][y]=0;
       for(int i=0;i<4;i++)
       {
           dfs(grid,x+dx[i],y+dy[i]);
       }
   }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               if(i==0 or j==0 or i==n-1 or j==m-1)
               {
                   if(grid[i][j]==1)
                       dfs(grid,i,j);
               }
           }
       }
        int c=0;
        for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               //if(i==0 or j==0 or i==n-1 or j==m-1)
               {
                   if(grid[i][j]==1)
                      c++;
               }
           }
       }
        return c;
        
            
            
    }
};