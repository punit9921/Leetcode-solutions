// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    vector<vector<int>>dp;
    int solve(int sum,int a[],int b[],int n,vector<vector<int>>&dp)
    {
       if(n==0 or sum==0)
       {
           return 0;
           
       }
       if(dp[n][sum]!=-1)
       return dp[n][sum];
       if(a[n-1]<=sum)
       return dp[n][sum]=max(solve(sum-a[n-1],a,b,n-1,dp)+b[n-1],solve(sum,a,b,n-1,dp));
       else
       return dp[n][sum]=solve(sum,a,b,n-1,dp);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       dp=vector<vector<int>>(n+1,vector<int>(W+1,-1));
       return solve(W,wt,val,n,dp);
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends