class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& a) {
        stack<int>s;
        vector<int>ans(a.size());
       for(int i=2*a.size()-1;i>=0;i--)
       {
           while(!s.empty() and a[s.top()]<=a[i%a.size()])
               s.pop();
           if(s.empty())
               ans[i%a.size()]=-1;
           else
               ans[i%a.size()]=a[s.top()];
           s.push(i%a.size());
       }
      //  reverse(ans.begin(),ans.end());
        return ans;
    }
};