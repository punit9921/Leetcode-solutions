class Solution {
public:
    int minAddToMakeValid(string s) {
      int cnt=0;
        int ans=0;
        stack<int>st;
        for(auto it:s)
        {
            if(it=='(')
                cnt++;
            else if(it==')')
            {
                cnt--;
            }
            if(cnt<0)
            {
                ans++;
                cnt=0;
            }
        }
        return ans+=cnt;
    }
};