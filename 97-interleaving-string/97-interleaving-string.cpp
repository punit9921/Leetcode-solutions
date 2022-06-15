class Solution {
public:
    unordered_map<string,bool>mem;
    bool solve(string s1,string s2,string s3,int ind1,int ind2,int ind3)
    {
        if(ind3==s3.size())
        {
            if(ind1==s1.size() and ind2==s2.size())
                return true;
            return false;
        }
        string key=to_string(ind1)+"*"+to_string(ind2)+"*"+to_string(ind3);
        if(mem.find(key)!=mem.end())
            return mem[key];
        if(ind1==s1.size())
            return mem[key]=s2[ind2]==s3[ind3]?solve(s1,s2,s3,ind1,ind2+1,ind3+1):false;
        if(ind2==s2.size())
            return mem[key]=s1[ind1]==s3[ind3]?solve(s1,s2,s3,ind1+1,ind2,ind3+1):false;
        bool flag1=false;
        bool flag2=false;
        if(s1[ind1]==s3[ind3])
            flag1=solve(s1,s2,s3,ind1+1,ind2,ind3+1);
        if(s2[ind2]==s3[ind3])
            flag2=solve(s1,s2,s3,ind1,ind2+1,ind3+1);
        return mem[key]=(flag1 or flag2);
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size()!=s1.size()+s2.size())
            return false;
        return solve(s1,s2,s3,0,0,0);
    }
};