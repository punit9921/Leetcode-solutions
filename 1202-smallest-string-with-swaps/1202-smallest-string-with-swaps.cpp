class Solution {
public:
    vector<int>par;
    int find(int node)
    {
        if(par[node]==node)
            return node;
        return par[node]=find(par[node]);
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n=s.size();
        par.resize(n);
        for(int i=0;i<n;i++)
            par[i]=i;
        for(auto it:pairs)
        {
            int u=it[0],v=it[1];
            u=find(u);
            v=find(v);
            if(u!=v)
                par[v]=u;
        }
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<par.size();i++)
        {
            mp[find(i)].push_back(i);
        }
        for(auto it:mp)
        {
            string st="";
            for(auto i:it.second)
                st+=s[i];
            sort(st.begin(),st.end());
            int j=0;
            for(auto i:it.second)
                s[i]=st[j++];
        }
        return s;
    }
};