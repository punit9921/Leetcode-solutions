// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 
  
int maximizeSum(int a[], int n);



int main()
{
    
    int t;cin>> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr, arr+n);
        
        cout << maximizeSum(arr, n) << endl;
        
        
    }

}

// } Driver Code Ends


int maximizeSum(int a[], int n) 
{
    // Complete the function
    int mx=*max_element(a,a+n);
    map<int,int>freq;
    for(int i=0;i<n;i++)
    freq[a[i]]++;
    int ele=mx;
    int ans=0;
    while(ele>0)
    {
        if(freq[ele]>0)
        {
            ans+=ele;
            freq[ele-1]--;
            freq[ele]--;
            
        }
        else
        ele--;
    }
    return ans;
}
