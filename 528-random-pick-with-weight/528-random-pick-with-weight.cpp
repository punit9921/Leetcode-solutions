class Solution {
public:
    vector<int>prefix;
    Solution(vector<int>& w) {
        int sum=0;
        for(auto it:w)
        {
            sum+=it;
            prefix.push_back(sum);
        }
    }
    int bs(int target,vector<int>&prefix)
    {
        int low=0,high=prefix.size();
        while(low<high)
        {
            int mid=(low+high)/2;
            if(prefix[mid]>=target)
                high=mid;
            else
                low=mid+1;
            
        }
        return low;
    }
    int pickIndex() {
        int n=prefix.size();
        int random=(ceil)(rand()*1.0/RAND_MAX*(prefix[n-1]));
        return bs(random,prefix);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */