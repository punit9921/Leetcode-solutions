class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        if(grid.size()==1)
            return grid[0][0];
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        q.push({grid[0][0],{0,0}});
               vector<int>vis(grid.size()*grid.size(),0);
                int ans=INT_MIN;
                vis[grid[0][0]]=1;
                int n=grid.size(),m=grid[0].size();
                int dirx[]={-1,1,0,0};
                int diry[]={0,0,-1,1};
        while(!q.empty())
        {
            auto temp=q.top();
            q.pop();
            ans=max(ans,temp.first);
            int x=temp.second.first;
            int y=temp.second.second;
            if(x==n-1 and y==m-1)
                return ans;
            for(int i=0;i<4;i++)
            {
                int row=x+dirx[i];
                int col=y+diry[i];
                if(row>=0 and row<n and col>=0 and col<m and vis[grid[row][col]]==0)
                {
                    vis[grid[row][col]]=1;
                    q.push({grid[row][col],{row,col}});
                }
            }
        }
                return ans;
    }
};