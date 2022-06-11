class Solution {
public:
   
    int minOperations(vector<int>& nums, int x) {
        int sum=0;
        for(auto it:nums)
            sum+=it;
        map<int,int>mp;
        int target=sum-x;
        int mx=INT_MIN;
        sum=0;
        mp[0]=-1;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            mp[sum]=i;
            if(mp.find(sum-target)!=mp.end())
                mx=max(mx,i-mp[sum-target]);
            
        }
        return mx==INT_MIN?-1:nums.size()-mx;
    }
};