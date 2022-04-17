class Solution {
public:
    string longestPalindrome( string s)
    {
      int n=s.size();
        string ans="";
        int left=0,right=0;
        for(int i=0;i<=n;i++)
        {
             left=i,right=i;
            while(left>=0 and right<n and s[left]==s[right])
            {
                int strlen=right-left+1;
                if(ans.size()<strlen)
                    ans=s.substr(left,strlen);
                left--;
                right++;
            }
            left=i,right=i+1;
            while(left>=0 and right<n and s[left]==s[right])
            {
                int strlen=right-left+1;
                if(ans.size()<strlen)
                    ans=s.substr(left,strlen);
                left--;
                right++;
            }
        }
        return ans;
        
    }
};