class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int start=0,end=0;
        int ans=0;
        int n=arr.size();
        while(start<n)
        {
            end=start;
            if(end+1<n and arr[end]<arr[end+1])
            {
                while(end+1<n and arr[end]<arr[end+1])
                    end++;
                if(end+1<n and arr[end]>arr[end+1])
                {
                    while(end+1<n and arr[end]>arr[end+1])
                        end++;
                    ans=max(ans,end-start+1);
                }
                
            }
            start=max(start+1,end);
            
        }
        return ans;
    }
};