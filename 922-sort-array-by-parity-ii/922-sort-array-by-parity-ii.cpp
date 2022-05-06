class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int i=0,j=1;
        while(i<nums.size())
        {
            while(i<nums.size() and nums[i]%2==0)
                i+=2;
            while(j<nums.size() and nums[j]%2)
                j+=2;
            if(i<nums.size())
            {
                swap(nums[i],nums[j]);
            }
            i+=2;
            j+=2;
        }
        return nums;
    }
};