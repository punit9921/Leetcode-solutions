class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,priority_queue<int,vector<int>,greater<int>>>mp;
        int need=0;
        for(auto it:nums)
        {
            if(mp[it-1].empty()==false)
            {
                int cnt=mp[it-1].top();
                mp[it-1].pop();
                mp[it].push(++cnt);
                
                if(cnt==3)
                    need--;
            }
            else
            {
                mp[it].push(1);
                need++;
            }
        }
        return need==0;
    }
};