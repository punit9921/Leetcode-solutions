class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& nums) {
        vector<int>lis;
        for(int i=0;i<nums.size();i++)
        {
            int ele=nums[i];
            if(lis.empty() or lis.back()<=ele)
            {
                lis.push_back(ele);
                nums[i]=lis.size();
            }
            else
            {
                int ind=upper_bound(lis.begin(),lis.end(),ele)-lis.begin();
                lis[ind]=ele;
                nums[i]=ind+1;
            }
                
        }
        return nums;
    }
};