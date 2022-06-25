class Solution {
public:
    int help(vector<int>&nums,int k)
    {
         map<int,int>mp;
        int j=0;
        int ans=0;
        int n=nums.size();
        int distinct=0;
        for(int i=0;i<nums.size();i++)
        {
            
            mp[nums[i]]++;
            if(mp.size()<=k)
            {
                ans+=(i-j+1);
            }
            else
            {
            while(j<=i and   mp.size()>k)
            {
                mp[nums[j]]--;
                if(mp[nums[j]]==0)
                {   mp.erase(nums[j]);
                
                }
               
                j++;
                
            }
            ans+=i-j+1;
            }
            
        }
        //>=   <=
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       return help(nums,k)-help(nums,k-1);
    }
};