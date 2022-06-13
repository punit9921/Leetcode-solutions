class Solution {
public:
     bool valid(int rsize,int csize,int r,int c){
        if(rsize<=r||csize<=c||c<0||r<0)return false;
        return true;
    }
    int dfs(vector<vector<int>>&grid,int row,int col)
    {
        int n=grid.size();
        int m=grid[0].size();
        if(row==n)
            return col;
        if(valid(n,m,row,col))
        {
            if(grid[row][col]==1)
            {
                if(valid(n,m,row,col+1) and grid[row][col+1]==1)
                    return dfs(grid,row+1,col+1);
            }
            else
            {
                if(row>=0 and col-1>=0 and row<n and col-1<m and grid[row][col-1]==-1)
                    return dfs(grid,row+1,col-1);
            }
        }
        return -1;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int>ans(m,0);
        for(int i=0;i<m;i++)
        {
            ans[i]=dfs(grid,0,i);
        }
        return ans;
    }
};