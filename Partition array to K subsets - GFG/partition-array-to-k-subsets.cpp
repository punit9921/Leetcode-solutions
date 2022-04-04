// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
  bool help(int a[],int n,int k,int ind,int sum,int curr,vector<bool>&vis)
  {
      if(k==1)
      return true;
      if(sum==curr)
      return help(a,n,k-1,0,sum,0,vis);
      for(int i=ind;i<n;i++)
      {
          if(vis[i] or curr+a[i]>sum)
          continue;
          vis[i]=true;
          if(help(a,n,k,i+1,sum,curr+a[i],vis))
          return true;
          vis[i]=false;
      }
      return false;
  }
    bool isKPartitionPossible(int a[], int n, int k)
    {
         //Your code here
         int sum=0;
         for(int i=0;i<n;i++)
         sum+=a[i];
         if(k==1)
         return true;
         if(n<k)
         return false;
         if(sum%k)
         return false;
         vector<bool>vis(n,false);
         return help(a,n,k,0,sum/k,0,vis);
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
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}  // } Driver Code Ends