class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
      long long  int low=1,high=1e7;
        int ans=0;
        while(low<=high)
        {
           long long int mid=(low+high)/2;
           long long int sum=0;
            for(auto it:candies)
                sum+=it/mid;
            if(k<=sum)
            {
                ans=mid;
                low=mid+1;
            }
            else
                high=mid-1;
        }
        return ans;
    }
};