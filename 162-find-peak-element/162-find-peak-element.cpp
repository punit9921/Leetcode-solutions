class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();  //size of array
        if(n==1)
            return 0;
        int low=0,high=n-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            bool left=false;
            bool right=false;
            
            if(mid==0 or nums[mid]>nums[mid-1])  //check for left neighbour
                left=true;
            
            if(mid==n-1 or nums[mid]>nums[mid+1])  //check for right neighbour
                right=true;
            
            if(left==true and right==true)
                return mid;
            
            if(left==true)
                low=mid+1;
            else
                high=mid-1;
        }
        return -1;
    }
};

