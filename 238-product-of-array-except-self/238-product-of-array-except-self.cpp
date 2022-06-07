class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n,1);
        int frombegin=1;
        int fromend=1;
        
        for(int i=0;i<n;i++)
        {
            res[i]*=frombegin;
            frombegin*=nums[i];
            res[n-i-1]*=fromend;
            fromend*=nums[n-i-1];
        }
        return res;
        
    }
};