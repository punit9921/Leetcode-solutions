class Solution {
public:
    unordered_map<string,bool>mp;
    bool solve(string s1,string s2)
    {
        if(s1.compare(s2)==0)
            return true;
        if(s1.size()<=1)
            return false;
        string key=s1;
        key+=" ";
        key+=s2;
        if(mp.find(key)!=mp.end())
        {
            return mp[key];
        }
        int n=s1.size();
        for(int i=1;i<n;i++)
        {
            if((solve(s1.substr(0,i),s2.substr(n-i,i)) and solve(s1.substr(i,n-1),s2.substr(0,n-i))) or (solve(s1.substr(0,i),s2.substr(0,i)) and solve(s1.substr(i,n-1),s2.substr(i,n-1)) ))
                return mp[key]=true;
        }
        return mp[key]=false;
    }
    bool isScramble(string s1, string s2) {
        if(s1.size()!=s2.size())
            return false;
        if(s1.size()==0 and s2.size()==0)
            return true;
        return solve(s1,s2);
    }
};