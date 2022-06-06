// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int target) {
        // Your code goes here
        int n=arr.size();
        sort(begin(arr),end(arr));
        set<vector<int>>s;
        for(int i=0;i<n-3;i++)
        {
            for(int j=i+1;j<n-2;j++)
            {
               int k=j+1;
               int l=n-1;
               while(k<l)
               {
               if(target==(arr[i]+arr[j]+arr[k]+arr[l]))
               {
                   vector<int>v;
                   v.push_back(arr[i]);
                   v.push_back(arr[j]);
                   v.push_back(arr[k]);
                   v.push_back(arr[l]);
                   s.insert(v);
                   k++;
               }
               else if(target>(arr[i]+arr[j]+arr[k]+arr[l]))
               {
                   k++;
               }
               else
               l--;
               
               }
            }
        }
        vector<vector<int>>ans;
        for(auto it:s)
        {
            ans.push_back(it);
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends