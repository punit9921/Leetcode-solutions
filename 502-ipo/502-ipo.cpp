class Solution {
public:
    static bool cmp(pair<int,int>&a,pair<int,int>&b)
    {
        return a.second<b.second;
    }
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>>v;
        for(int i=0;i<profits.size();i++)
        {
            v.push_back({profits[i],capital[i]});
        }
        sort(v.begin(),v.end(),cmp);
        int ans=0;
        priority_queue<int>pq;
        int i=0;
        while(k)
        {
            while(i<profits.size() and v[i].second<=w)
                pq.push(v[i++].first);
            if(!pq.empty())
            {
                w+=pq.top();
                pq.pop();
            }
            k--;
        }
        return w;
    }
};