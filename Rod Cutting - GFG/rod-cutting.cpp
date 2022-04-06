// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        int arr[n];
        for(int i=0;i<n;i++)
        arr[i]=i+1;
        
        int dp[n+1][n+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0 or j==0)
                {
                    dp[i][j]=0;
                    continue;
                }
                if(arr[i-1]<=j)
                dp[i][j]=max(dp[i-1][j],dp[i][j-arr[i-1]]+price[i-1]);
                else
                dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][n];
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends