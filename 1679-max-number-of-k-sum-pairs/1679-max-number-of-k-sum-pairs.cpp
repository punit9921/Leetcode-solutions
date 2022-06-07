class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int cnt=0;
        map<int,int>mp;
        for(auto it:nums)
            mp[it]++;
        for(int i=0;i<nums.size();i++)
        {
            if(mp[nums[i]]>0)
            {
                mp[nums[i]]--;
                if(mp[k-nums[i]]>0)
                {
                    cnt++;
                   
                    mp[k-nums[i]]--;
                }
                else
                    mp[nums[i]]++;
            }
        }
        return cnt;
    }
};