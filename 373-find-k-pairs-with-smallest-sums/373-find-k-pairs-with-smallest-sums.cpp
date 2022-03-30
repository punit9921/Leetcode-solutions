class Solution {
public:
   
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>>ans;
       /* priority_queue<pair<int,pair<int,int>>>pq;
        for(int i=0;i<min((int)nums1.size(),k);i++)
        {
            for(int j=0;j<min((int)nums2.size(),k);j++)
            {
                int sum=nums1[i]+nums2[j];
                if(pq.size()<k)
                    pq.push({sum,{nums1[i],nums2[j]}});
                else
                {
                    if(nums1[i]+nums2[j]<pq.top().second.first+pq.top().second.second)
                    {
                        pq.pop();
                        pq.push({sum,{nums1[i],nums2[j]}});
                    }
                    else
                        break;
                }
            }
        }
        while(!pq.empty())
        {
            ans.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        return ans;*/
        
        int n1=nums1.size(),n2=nums2.size();
        priority_queue<vector<int>,vector<vector<int>>,greater<>>pq;
        for(int i=0;i<min(n1,k);i++)
            pq.push({nums1[i]+nums2[0],i,0});
        while(!pq.empty())
        {
            auto temp=pq.top();
            pq.pop();
            int val=temp[0];
            int x=temp[1];
            int y=temp[2];
            ans.push_back({nums1[x],nums2[y]});
            if(ans.size()==k)
                return ans;
            if(y+1<n2)
            {
                pq.push({nums1[x]+nums2[y+1],x,y+1});
            }
        }
        return ans;
        
    }
};