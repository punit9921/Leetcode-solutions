// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution {
public:    
    vector<int> rotation(int n)
    {
        // Code Heree
        vector<int>ans;
        deque<int>dq;
        dq.push_front(n);
        for(int i=1;i<n;i++)
        {
            dq.push_front(n-i);
            for(int j=0;j<n-i;j++)
            {
                int back=dq.back();
                dq.pop_back();
                dq.push_front(back);
            }
        }
        while(!dq.empty())
        {
            ans.push_back(dq.front());
            dq.pop_front();
        }
        return ans;
    }
};


// { Driver Code Starts.

int main()
{
    Solution obj;
    int t;
    cin>>t;
    while(t--)
    {
        int n; cin >> n;
        vector<int > ans;
        ans = obj.rotation(n);
        for(int i:ans)
            cout<< i << " ";
        cout << endl;
        
    }
    return 0;
}
  // } Driver Code Ends