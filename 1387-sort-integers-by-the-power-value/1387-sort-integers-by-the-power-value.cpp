class Solution {
public:
  
    int power(int i)
    {
        
        if(i==1)
            return 1;
        int cnt=0;
        if(i%2)
        {
            cnt=1+power(3*i+1);
        }
        else
            cnt=1+power(i/2);
        return cnt;
    }
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>>v;
       // memset(dp,-1,sizeof(dp));
        for(int i=lo;i<=hi;i++)
        {
            v.push_back({power(i),i});
            
        }
        sort(begin(v),end(v));
        return v[k-1].second;
    }
};