class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
         vector<vector<int> > ans(n, vector<int>(n));
    
        int rows = 0, rowe = n - 1;
        int cols = 0, cole = n - 1;
        int val=1;
    
        while(val<=n*n)
        {
            //top row
            for(int i = cols; i<= cole; i++)
                ans[rows][i] = val++;
            rows++;
        
            //right column
            for(int i = rows; i<= rowe; i++)
                ans[i][cole] = val++;
            cole--;
        
            //bottom row
            for(int i = cole; i>= cols; i--)
                ans[rowe][i] = val++;
            rowe--;
        
            //left column
            for(int i = rowe; i>= rows; i--)
                ans[i][cols] = val++;
            cols++;
        }
    return ans;
    }
};