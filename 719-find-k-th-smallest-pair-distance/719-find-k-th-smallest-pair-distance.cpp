class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(begin(nums),end(nums));
        int low=0,high=nums[nums.size()-1]-nums[0];
        int ans=0;
        while(low<=high)
        {
            int mid=(low+high)/2;
            int cnt=0;
            int j=1,i=0;
            while(j<nums.size())
            {
                if(i==j)
                {
                    j++;
                    continue;
                }
             if(nums[j]-nums[i]<=mid)
                {
                    j++;
                }
                else
                {
                    cnt+=(j-i-1);
                    i++;
                }
                    
                
            }
            while(j>i)
            {
                cnt+=(j-i-1);
                i++;
            }
            if(cnt>=k)
            {
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
};


   