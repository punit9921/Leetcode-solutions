class Solution {
public:
    int trapRainWater(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 or j==0 or i==m-1 or j==n-1)
                {
                    pq.push({mat[i][j],{i,j}});
                    vis[i][j]=true;
                }
            }
        }
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        int ans=0;
        while(!pq.empty())
        {
            int val=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 and ny>=0 and nx<m and ny<n and vis[nx][ny]==false)
                {
                    vis[nx][ny]=true;
                    ans+=max(0,val-mat[nx][ny]);
                    pq.push({max(val,mat[nx][ny]),{nx,ny}});
                }
            }
        }
        return ans;
    }
};

// 1 4 3 1 3 2
// 3 2  4 4 4
// 2 3 3 2 3 1