class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i=0;
        map<int,int>mp;
        int ans=1;
        for(int j=0;j<fruits.size();j++)
        {
            mp[fruits[j]]++;
            while(mp.size()>2)
            {
              //  ans=max(ans,j-i+1);
                mp[fruits[i]]--;
                if(mp[fruits[i]]==0)
                    mp.erase(fruits[i]);
                i++;
            }
            ans=max(ans,j-i+1);
            
        }
        return ans;
    }
};