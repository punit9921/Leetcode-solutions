class Solution {
public:
   
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
         priority_queue<int>pq;
        multiset<pair<int,int>>ms;
        int final_capital=w;
        for(int i=0;i<capital.size();i++)
        {
            if(capital[i]<=w)
                pq.push(profits[i]);
            else
                ms.insert({profits[i],capital[i]});
        }
        while(pq.size()>0 and k--)
        {
            final_capital+=pq.top();
            pq.pop();
            for(auto it:ms)
            {
                if(it.second<=final_capital)
                {
                    pq.push(it.first);
                    ms.erase(ms.find(it));
                }
            }
        }
        return final_capital;
    }
};