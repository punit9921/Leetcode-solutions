// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
int dx[8]={1,1,1,-1,-1,-1,0,0};
int dy[8]={1,0,-1,1,0,-1,1,-1};
bool check(vector<vector<char>>&grid,int r,int c,int n,int m,int pos,int k,string &word)
{
    if(pos==word.size())
    return true;
    if(r<0 or c<0 or r>=n or c>=m or grid[r][c]!=word[pos])
    return false;
    return check(grid,r+dx[k],c+dy[k],n,m,pos+1,k,word);
}
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	    int n=grid.size();
	    int m=grid[0].size();
	    vector<vector<int>>ans;
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	           if(word[0]==grid[i][j])
	           {
	               for(int k=0;k<8;k++)
	               {
	                   if(check(grid,i,j,n,m,0,k,word))
	                   {ans.push_back({i,j});
	                   break;
	                   }
	               }
	           }
	        }
	    }
	   
	    return ans;
	  
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
	}
	return 0;
}  // } Driver Code Ends