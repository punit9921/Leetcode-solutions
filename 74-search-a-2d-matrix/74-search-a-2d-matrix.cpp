class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int i=0,j=m*n-1;
        while(i<=j)
        {
          int mid=(i+j)/2;
            int ele=matrix[mid/ m][mid%m];
            if(ele==target)
                return true;
            else if(ele > target)
                j=mid-1;
            else
                i=mid+1;
        }
        return false;
    }
};