class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>>temp=board;
        int n=board.size();
        int m=board[0].size();
        int dirx[]={1,-1,0,0,1,1,-1,-1};
        int diry[]={0,0,1,-1,1,-1,1,-1};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int cnt=0;
                for(int i1=0;i1<8;i1++)
                {
                    int x=i+dirx[i1];
                    int y=j+diry[i1];
                 //   cout<<x<<" "<<y<<endl;
                    if(x>=0 and y>=0 and x<n and y<m)
                    {
                        if(temp[x][y]==1)
                            cnt++;
                    }
                }
                
                if(temp[i][j]==0)
                {
                    if(cnt==3)
                        board[i][j]=1;
                }
                else
                {
                    if(cnt<2)
                        board[i][j]=0;
                    else if(cnt>3)
                        board[i][j]=0;
                    else 
                        board[i][j]=1;
                }
            }
        }
    }
};