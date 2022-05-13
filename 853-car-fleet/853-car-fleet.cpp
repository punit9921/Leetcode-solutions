class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>>v;
        for(int i=0;i<position.size();i++)
        {
            v.push_back({position[i],(double)(target-position[i])/(double)speed[i]});
        }
        sort(begin(v),end(v));
        pair<int,double>p=v[v.size()-1];
        int cnt=0;
        for(int i=v.size()-2;i>=0;i--)
        {
            if(v[i].second>p.second)
            {
                cnt++;
                p=v[i];
            }
        }
        return cnt+1;
    }
};