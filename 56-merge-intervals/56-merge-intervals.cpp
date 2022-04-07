class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
      int n=a.size();  //size of vector
        vector<vector<int>>merged_intervals;  //for storing merged intervals
        sort(a.begin(),a.end());
        vector<int>temp=a[0];
        for(auto it:a)
        {
            if(it[0]<=temp[1])
                temp[1]=max(it[1],temp[1]);
            else
            {
                merged_intervals.push_back(temp);
                temp=it;
            }
                
        }
        merged_intervals.push_back(temp);
        return merged_intervals;
    }
};

/*


v[i]   v[j]
i<j
v[i][1]>v[j][0]

1,3   2,6
1,6
*/