class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        map<char,int>mp;
        int start=0,ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(mp.find(s[i])!=mp.end())
            {
                start=max(start,mp[s[i]]+1);
            }
            mp[s[i]]=i;
            ans=max(ans,i-start+1);
        }
        if(ans==INT_MIN)
            return 0;
        return ans;
    }
};