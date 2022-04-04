class Solution {
public:
    int minOperations(vector<int>&arr) {
      set<int>s;
        int n=arr.size();
        for(auto it:arr)
        {
            s.insert(it);
        }
        vector<int>temp;
        for(auto it:s)
            temp.push_back(it);
        
        //original array : 1 2 2 4 8 7
        //sorted array   : 1 2 4 8 7
        int ans=INT_MIN,ind=0;
        for(int i=0;i<temp.size();i++)
        {
            while(ind<temp.size() and temp[ind]<=temp[i]+n-1)
                ind++;
            ans=max(ans,ind-i);
        }
        return n-ans;
    }
};


// let's say our max element is a[j] and our min element is a[i]
// so what we want is a[j]-a[i]==N-1
//     so lets say we are having a[i] and N
//     so a[j]=a[i]+N-1