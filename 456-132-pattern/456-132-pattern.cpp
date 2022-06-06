class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int>s;
        int val=INT_MIN;
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(nums[i]<val)
                return true;
            else
            {
                while(!s.empty() and nums[i]>s.top())
                {
                    val=s.top();
                    s.pop();
                }
            }
            s.push(nums[i]);
        }
        return false;
    }
};