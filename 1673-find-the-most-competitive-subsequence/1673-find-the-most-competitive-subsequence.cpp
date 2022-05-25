class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        stack<int>s;
        for(int i=0;i<nums.size();i++)
        {
            while(!s.empty() and s.top()>nums[i] and s.size()+nums.size()-i-1>=k)
                s.pop();
            if(s.size()<k)
                s.push(nums[i]);
        }
        vector<int>ans;
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
            
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};