class Solution {
public:
    int uniquePaths(int m, int n) {
//         int dp[m][n];
//        for(int i=0;i<m;i++)
//        {
//            for(int j=0;j<n;j++)
//            {
//                if(i==0 or j==0)
//                    dp[i][j]=1;
//                else
//                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
//            }
//        }
        
//         return dp[m-1][n-1];
//     }
         int N = n+m-2; 
        int r = min(n,m) - 1; 
        
        double res = 1;
        
		
        for(int i=1; i<=r; ++i, N--){
            
            res = res * (N) / i;
        }
        
        return (int)res;
    }
        
};