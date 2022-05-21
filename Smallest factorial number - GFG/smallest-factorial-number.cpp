// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    int solve(int x)
    {
        if(x<=1)
        {
            return x;
        }
        return x+solve(x/5);
    }
        int findNum(int n)
        {
        //complete the function here
         int l=1,r=n;
        while(l<=r)
        {
            int mid=(l+r)/2;
            int x=solve(mid);
            if(x==n)
            return 5*mid;
            else if(x>n)
            r=mid-1;
            else
            l=mid+1;
        }
        return 5*l;
        }
};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}  // } Driver Code Ends