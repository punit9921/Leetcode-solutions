class Solution {
public:
    bool res;
    void dfs(int x,int y,vector<vector<int>>&grid1,vector<vector<int>>&grid2,vector<vector<int>>&vis)
    {
        int n=grid1.size();
        int m=grid1[0].size();
        if(x<0 or y<0 or x>=n or y>=m or grid2[x][y]==0)
            return;
        if(grid1[x][y]==0 )
        {
            res=false;
            return;
        }
        grid2[x][y]=0;
        dfs(x+1,y,grid1,grid2,vis);
        dfs(x,y+1,grid1,grid2,vis);
        dfs(x-1,y,grid1,grid2,vis);
        dfs(x,y-1,grid1,grid2,vis);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid1.size();
        int m=grid1[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if( grid2[i][j]==1)
                {
                    res=true;
                    dfs(i,j,grid1,grid2,vis);
                    if(res)
                        cnt++;
                }
            }
        }
        return cnt;
    }
};