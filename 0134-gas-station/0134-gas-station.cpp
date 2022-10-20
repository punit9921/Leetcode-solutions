class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int total=0;
        int curr=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            total+=gas[i]-cost[i];
            curr+=gas[i]-cost[i];
            if(curr<0)
            {
                curr=0;
                ans=i+1;
            }
        }
        if(total<0)
            return -1;
        return ans;
    }
};