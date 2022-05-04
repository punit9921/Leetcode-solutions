class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        deque<vector<int>>q;
        q.push_back({points[0][0],points[0][1]-points[0][0]});
            int ans=INT_MIN;
           for(int i=1;i<points.size();i++)
            {
                while(!q.empty() and points[i][0]-q.front()[0]>k)
                    q.pop_front();
               if(!q.empty())
               {
                   ans=max(ans,q.front()[1]+points[i][0]+points[i][1]);
               }
               int val=points[i][1]-points[i][0];
               while(!q.empty() and q.back()[1]<=val)
                   q.pop_back();
               q.push_back({points[i][0],val});
                   
               
            }
        return ans;
    }
};