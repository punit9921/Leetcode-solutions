class Solution {
public:
    bool check(vector<int>&pos,int mid,int m)
    {
        int p=pos[0];
        int cnt=1;
        for(int i=1;i<pos.size();i++)
            {
              if(pos[i]-p>=mid)
              {
                  p=pos[i];
                  cnt++;
              }
            if(cnt==m)
                return true;
            }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(begin(position),end(position));
        int low=1;
        int high=1e9;
        int ans=0;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(check(position,mid,m))
            {
                ans=mid;
                low=mid+1;
            }
            else
                high=mid-1;
        }
        return ans;
    }
};