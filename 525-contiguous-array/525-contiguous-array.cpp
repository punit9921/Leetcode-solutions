class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int,int>mp;
        int sum=0;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
                sum+=-1;
            else
                sum+=1;
            if(sum==0)
                ans=max(ans,i+1);
            if(mp.find(sum)==mp.end())
                mp[sum]=i;
            else
                ans=max(ans,i-mp[sum]);
        }
        return ans;
    }
};