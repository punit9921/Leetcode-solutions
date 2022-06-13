class Solution {
public:
    const int mod=1e9+7;
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int i=0,j=0;
       long long int sum1=0,sum2=0;
        while(i<n or j<m)
        {
            if(i<n and (j==m or nums1[i]<nums2[j] ))
                sum1+=nums1[i++];
            else if(j<m and (i==n or nums1[i]>nums2[j] ))
                sum2+=nums2[j++];
            else
            {
                sum1=sum2=max(sum1,sum2)+nums1[i];
                i++,j++;
            }
        }
        return max(sum1,sum2)%mod;
    }
};