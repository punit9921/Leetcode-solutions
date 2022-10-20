class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        int ans=0;
        vector<int>arr(n,1);
        for(int i=1;i<n;i++)
        {
            if(ratings[i]>ratings[i-1])
                arr[i]=arr[i-1]+1;
        }
        for(int i=n-1;i>=1;i--)
        {
            if(ratings[i]<ratings[i-1])
                arr[i-1]=max(arr[i-1],arr[i]+1);
        }
        for(auto it:arr)
            ans+=it;
        return ans;
    }
};