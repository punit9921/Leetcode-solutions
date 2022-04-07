class Solution {
public:
    bool issafe(int i,int j,int n,int m)
    {
        if(i<0 or j<0 or i>=n or j>=m)
            return false;
        return true;
    }
    void dfs(vector<vector<char>>&board,int row,int col,vector<vector<bool>>&vis )
    {
        int n=board.size();
        int m=board[0].size();
        if(!issafe(row,col,n,m) or vis[row][col]==true or board[row][col]=='X')
            return;
        
        vis[row][col]=true;
        dfs(board,row+1,col,vis);
        dfs(board,row,col+1,vis);
        dfs(board,row-1,col,vis);
        dfs(board,row,col-1,vis);
        return ;
        
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        
        vector<vector<bool>>vis(n,vector<bool>(m,false));  //visited array
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 or j==0 or i==n-1 or j==m-1)//boundary points
                {
                    if(board[i][j]=='O' and vis[i][j]==false)
                    {
                        dfs(board,i,j,vis);
                    }
                }
            }
        }
        for(int i=1;i<n-1;i++)
        {
            for(int j=1;j<m-1;j++)
            {
                if(board[i][j]=='O' and vis[i][j]==false)
                {
                    board[i][j]='X';
                }
            }
        }
    }
};