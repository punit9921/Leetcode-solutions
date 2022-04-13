class Solution {
public:
    bool isSubsequence(string s, string t) {
        int c=0;
        int i=0,j=0;
        while (i<s.size() and j<t.size())
        {
            if(s[i]==t[j])
            {
                i++;
                c++;
            }
            j++;
        }
        if(c==s.size())
            return true;
        else
            return false;
    }
};