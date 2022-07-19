class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start=0,mid=0,high=nums.size()-1;
        while(mid<=high)
        {
            if(nums[mid]==0)
            {
                swap(nums[mid],nums[start]);
                mid++;
                start++;
            }
            else if(nums[mid]==1)
                mid++;
            else
            {
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};