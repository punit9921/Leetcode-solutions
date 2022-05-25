class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      int n=nums.size();
        if(n==0)
            return 0;
      unordered_map<int,bool>mp;
        for(int i=0;i<n;i++)
           mp[nums[i]]=true;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int tempnum=nums[i];
            int cnt=0;
            while(mp[tempnum]==true)
            {
                mp[tempnum]=false;
                tempnum++;
                cnt++;
            }
            tempnum=nums[i]-1;
            while(mp[tempnum]==true)
            {
                mp[tempnum]=false;
                tempnum--;
                cnt++;
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};