class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
//       vector<int>ans;
//         map<int,int>mp;
//         for(int i=0;i<nums.size();i++)
//             mp[nums[i]]++;
//         priority_queue<pair<int,int>>heap;
//     for(auto itr=mp.begin();itr!=mp.end();itr++)
//     {
//         heap.push({itr->second,itr->first});
       
//     }
//         while(k--)
//         {
//             ans.push_back(heap.top().second);
//             heap.pop();
//         }
//         return ans;
//     }
    vector<int>ans;
    map<int,int>freq;
    for(auto it:nums)
        freq[it]++;
    priority_queue<pair<int,int>>pq;
    for(auto it:freq)
    {
        pq.push({it.second,it.first});
    }
    while(k--)
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
    }
    
};