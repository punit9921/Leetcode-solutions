class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(begin(nums),end(nums));
        int ans=INT_MAX;
        int anssum=0;
        for(int i=0;i<nums.size()-2;i++)
        {
            int low=i+1,high=nums.size()-1;
            
            while(low<high)
            {
                int sum=nums[i]+nums[low]+nums[high];
                if(ans>abs(target-sum))
                    {
                        ans=abs(target-sum);
                    anssum=sum;
                    }
                if(sum==target)
                    return sum;
                else if(sum>target)
                {
                    high--;
                }
                else
                    low++;
               
                
            }
         
        }
        return anssum;
    }
};