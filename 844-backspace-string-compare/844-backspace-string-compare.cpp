class Solution {
public:
    bool backspaceCompare(string s, string t) {
       stack<char>s1,s2;
        for(int i=0;i<s.size();i++)
        {
            if(!s1.empty() and s[i]=='#')
                s1.pop();
            else if(s[i]=='#')
                continue;
            else
                s1.push(s[i]);
        }
        for(int j=0;j<t.size();j++)
        {
            if(!s2.empty() and t[j]=='#')
                s2.pop();
            else if(t[j]=='#')
                continue;
            else
                s2.push(t[j]);
        }
        if(s1.size()!=s2.size())
            return false;
        while(!s1.empty())
        {
            if(s1.top()!=s2.top())
                return false;
            s1.pop(),s2.pop();
        }
        return true;
    }
};