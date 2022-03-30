class Solution {
public:
    bool isPossible(vector<int>& nums) {
       unordered_map<int,int>subs,freq;
        for(auto it:nums)
        {
            freq[it]++;
        }
        for(auto it:nums)
        {
            if(!freq[it])
                continue;
            freq[it]--;
            if(subs[it-1]>0)
            {
                subs[it-1]--;
                subs[it]++;
            }
            else if(freq[it+1] and freq[it+2])
            {
                freq[it+1]--;
                freq[it+2]--;
                subs[it+2]++;
            }
            else
                return false;
        }
        return true;
    }
};