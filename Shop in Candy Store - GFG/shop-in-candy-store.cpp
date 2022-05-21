// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int k)
    {
        // Write Your Code here
        sort(candies,candies+N);
        int minans=0,maxans=0;
        int n=N;
        int i=0,j=n-1;
        while(i<=j)
        {
            minans+=candies[i];
            j-=k;
            i++;
            
        }
         i=0,j=n-1;
        while(i<=j)
        {
            maxans+=candies[j];
            j--;
            i+=k;
        }
        return {minans,maxans};
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}  // } Driver Code Ends