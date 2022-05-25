// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    long long int minSum(int arr[], int n)
    {
        // Your code goes here
        sort(arr,arr+n);
        long long sum1=0,sum2=0;
        for(int i=0;i<n;i+=2)
        {
            int j=i+1;
            if(i<n and arr[i]>=0)
            sum1=sum1*10+arr[i];
            if(j<n and arr[j]>=0)
            sum2=sum2*10+arr[j];
        }
        return sum1+sum2;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n+1];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.minSum(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends