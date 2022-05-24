class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();//size of array
        int i,j;
        for(i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                break;
            }
        }
        if(i<0)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        reverse(nums.begin()+i+1,nums.end());
        j=i+1;
         for(;j<n;j++)
            {
                if(nums[j]>nums[i])
                {
                   swap(nums[i],nums[j]);
                    return;
                }
            }
            
       
    }
};