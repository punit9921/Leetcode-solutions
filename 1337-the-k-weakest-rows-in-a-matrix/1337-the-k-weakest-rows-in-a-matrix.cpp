class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
             priority_queue<pair<int,int> > pq;
        vector<int> ans;
        for(int i = 0; i<mat.size(); ++i)
        {
            // calularing cnt of soldier
           int cnt=0;
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j]==1)
                    cnt++;
            }
			
			// instead  of using binary func for calculating cnt of 1
			// we can use this stl count function
			// int cnt = count(mat[i].begin(),mat[i].end(),1);
			
            pq.push(make_pair(cnt,i));
            
            // we need to maintain top k smallest elements
            if(pq.size() > k)
                pq.pop();
        }
        
        // making answer vector
        for(int i = 0; i<k; ++i)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }

};