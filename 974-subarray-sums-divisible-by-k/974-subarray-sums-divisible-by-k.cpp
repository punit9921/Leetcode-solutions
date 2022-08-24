class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum=0;
        map<int,int>mp;
        mp[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            int rem=(sum%k+k)%k;
            mp[rem]++;
        }
        int ans=0;
        for(auto it:mp)
        {
            if(it.second>1)
            {
                ans=ans+(it.second*(it.second-1))/2;
            }
            
        }
        return ans;
    }
};