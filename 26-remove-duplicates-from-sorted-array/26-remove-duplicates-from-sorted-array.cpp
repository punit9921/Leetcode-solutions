class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0,j=0;
        if(nums.size()<=1)
            return nums.size();
        for(;i<nums.size()-1;i++)
        {
            if(nums[i]!=nums[i+1])
            {
                nums[j++]=nums[i];
            }
        }
        nums[j++]=nums[nums.size()-1];
        return j;
    }
};