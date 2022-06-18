class RLEIterator {
public:
    vector<int>v;
    int cnt=0;
    int ind=0;
    RLEIterator(vector<int>& encoding) {
       v=encoding;
    }
    
    int next(int n) {
        
        while(ind<v.size())
        {
            if(v[ind]>=n)
            {
                v[ind]-=n;
                return v[ind+1];
            }
            else
            {
                n-=v[ind];
                ind+=2;
            }
        }
        return -1;
        
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */