class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int,int>mp;
        for(auto it:nums)
        {
            mp[it]++;
        }
        int sum=0;
        for(auto it:mp)
        {
            int val=(it.second*(it.second-1))/2;
            sum+=val;
        }
        return sum;
    }
};