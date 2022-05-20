// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    long long getSubstringWithEqual012(string str) {
        // code here
        map<pair<long long,long long>,long long>mp;
        int zc=0,oc=0,tc=0;
        long long cnt=0;
        mp[{0,0}]=1;
        for(auto it:str)
        {
            if(it=='0')
            zc++;
            else if(it=='1')
            oc++;
            else
            tc++;
            cnt+=mp[{zc-oc,zc-tc}];
            mp[{zc-oc,zc-tc}]++;
            
        }
        return cnt;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.getSubstringWithEqual012(s)<<endl;
	}
    return 0;
}
  // } Driver Code Ends