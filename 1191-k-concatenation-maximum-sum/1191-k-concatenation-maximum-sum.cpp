class Solution {
public:
    const int mod=1e9+7;
    int max_subarray_sum(vector<int>&v)
    {
        long long sum=0,maxsum=0;
        for(int i=0;i<v.size();i++)
        {
            sum=max(sum+(long long)v[i],(long long)v[i]);
            maxsum=max(sum,maxsum);
        }
        return maxsum%mod;
    }
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int n=arr.size();
        if(k==1)
        {
            return max_subarray_sum(arr);
        }
        long long asum=0;
        for(auto it:arr)
            asum+=it;
        vector<int>a=arr;
        for(int i=0;i<n;i++)
            a.push_back(arr[i]);
        long long sum=max_subarray_sum(a);
        return (sum+(asum>0?asum*(k-2):0))%mod;
            
    }
};