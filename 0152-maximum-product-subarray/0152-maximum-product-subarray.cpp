class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxprod=INT_MIN;
        int curr=1;
        for(int i=0;i<n;i++)
        {
            curr=curr*nums[i];
            maxprod=max(maxprod,curr);
            if(curr==0)
                curr=1;
        }
        curr=1;
        for(int i=n-1;i>=0;i--)
        {
            curr=curr*nums[i];
            maxprod=max(maxprod,curr);
            if(curr==0)
                curr=1;
        }
        return maxprod;
    }
};