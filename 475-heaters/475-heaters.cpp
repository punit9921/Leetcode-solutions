class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(begin(houses),end(houses));
        sort(begin(heaters),end(heaters));
        vector<int>res(houses.size(),INT_MAX);
        for(int i=0,h=0;i<houses.size() and h<heaters.size();)
        {
            if(houses[i]<=heaters[h])
            {
                res[i]=min(res[i],heaters[h]-houses[i]);
                i++;
            }
            else
                h++;
        }
        for(int i=houses.size()-1,h=heaters.size()-1;i>=0 and h>=0;)
        {
            if(houses[i]>=heaters[h])
            {
                res[i]=min(res[i],-1*(heaters[h]-houses[i]));
                i--;
            }
            else
                h--;
            
        }
        return *max_element(res.begin(),res.end());
    }
};