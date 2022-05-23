class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size() ;i++)
        {
            if(nums[i]>=0 or k==0)
                break;
            nums[i]=-1*nums[i];
            k--;
        }
        if(k!=0)
        {
            sort(nums.begin(),nums.end());
            if(k%2)
                nums[0]=-1*nums[0];
            
        }
        int sum=0;
        for(auto it:nums)
            sum+=it;
        return sum;
    }
};