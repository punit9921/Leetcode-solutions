class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
       int n=s.size(),m=p.size();
        vector<int> pattern(26,0),text(26,0);
        vector<int>ans;
        if(n<m)
            return {};
        for(int i=0;i<m;i++)
        {
            pattern[p[i]-'a']++;
            text[s[i]-'a']++;
        }
        if(pattern==text)
            ans.push_back(0);
        for(int i=m;i<n;i++)
        {
            text[s[i-m]-'a']--;
            text[s[i]-'a']++;
            if(text==pattern)
                ans.push_back(i-m+1);
        }
        return ans;
    }
};