// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int isLuckyOrNot(long long N) {
        // code here
        set<long long>s;
        if(N<=9*1LL)
        return 1;
        int cnt=0;
        while(N!=0)
        {
            if(N%10==1)
            return 0;
            s.insert(N%10);
            cnt++;
            N/=10;
        }
        return s.size()==cnt;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.isLuckyOrNot(N) << endl;
    }
    return 0;
}  // } Driver Code Ends