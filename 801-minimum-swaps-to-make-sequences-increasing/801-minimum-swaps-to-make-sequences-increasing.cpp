class Solution {
public:
    vector<vector<int>>dp;
    int n;
    int solve(vector<int>&nums1,vector<int>&nums2,int ind,int swapped)
    {
        if(ind==n)
            return 0;
        if(dp[ind][swapped]!=-1)
            return dp[ind][swapped];
        int prev1=nums1[ind-1];
        int prev2=nums2[ind-1];
        if(swapped)
            swap(prev1,prev2);
        int ans=INT_MAX;
        if(nums1[ind]>prev1 and nums2[ind]>prev2)
            ans=solve(nums1,nums2,ind+1,0);
        if(nums1[ind]>prev2 and nums2[ind]>prev1)
            ans=min(ans,1+solve(nums1,nums2,ind+1,1));
        return dp[ind][swapped]=ans;
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
      nums1.insert(nums1.begin(),-1);
      nums2.insert(nums2.begin(),-1);
      n=nums1.size();
        dp=vector<vector<int>>(n+1,vector<int>(2,-1));
        return solve(nums1,nums2,1,0);
    }
};