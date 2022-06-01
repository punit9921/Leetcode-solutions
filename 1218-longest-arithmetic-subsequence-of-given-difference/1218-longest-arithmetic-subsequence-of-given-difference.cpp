class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n=arr.size();
       unordered_map<int,int>dp;
        int mx=1;
        for(int i=0;i<n;i++)
        {
            dp[arr[i]]=1+dp[arr[i]-difference];
            mx=max(mx,dp[arr[i]]);
        }
        return mx;
    }
};