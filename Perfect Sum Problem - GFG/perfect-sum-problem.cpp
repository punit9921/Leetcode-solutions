// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	vector<vector<int>>dp;
	int mod=1000000007;
int solve(int arr[],int n,int sum)
{
    
    if(n==0)
    return dp[n][sum]=sum==0?1:0;
   
    if(dp[n][sum]!=-1)
    return dp[n][sum]%mod;
    if(arr[n-1]<=sum)
    return dp[n][sum]=(solve(arr,n-1,sum-arr[n-1])%mod + solve(arr,n-1,sum)%mod)%mod;
    else
    return dp[n][sum]=solve(arr,n-1,sum)%mod;
}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        dp=vector<vector<int>>(n+1,vector<int>(sum+1,-1));
        return solve(arr,n,sum);
	}
	  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends