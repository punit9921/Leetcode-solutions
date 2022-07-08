class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        long long int ans=0;
        int n=nums.size();
        vector<unordered_map<long long int,int>>dp(n);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                long long int diff=(long long)nums[i]-nums[j];
                dp[i][diff]+=dp[j][diff]+1;
                ans+=dp[j][diff];
            }
        }
        return ans;
    }
};