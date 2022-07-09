class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(),buses.end());
        sort(passengers.begin(),passengers.end());
        int pass_ind=0;
        int curr=0;
        map<int,int>mp;
        for(int i=0;i<buses.size();i++)
        {
            curr=0;
            while(pass_ind<passengers.size() and passengers[pass_ind]<=buses[i] and curr<capacity)
            {
                mp[passengers[pass_ind]]=1;
                curr++;
                pass_ind++;
            }
        }
        if(pass_ind==0)
            return buses[buses.size()-1];
        pass_ind--;
        int last=passengers[pass_ind];
        if(curr<capacity)
            last=buses[buses.size()-1];
        while(mp[last]==1)
            last--;
        return last;
    }
};