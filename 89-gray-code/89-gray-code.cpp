class Solution {
public:
    vector<string>help(int n)
    {
        if(n==1)
            return {"0","1"};
        vector<string>code=help(n-1);
        vector<string>ans;
        for(int i=0;i<code.size();i++)
            ans.push_back("0"+code[i]);
        for(int i=code.size()-1;i>=0;i--)
            ans.push_back("1"+code[i]);
        return ans;
    }
    vector<int> grayCode(int n) {
        vector<int>ans;
        for(auto it:help(n))
        {
            int val=stoi(it,0,2);
            ans.push_back(val);
        }
        return ans;
    }
};