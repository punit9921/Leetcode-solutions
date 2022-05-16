class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string>s;
        int cnt=0;
        for(auto it:logs)
        {
            string log=it;
            if(log=="./")
                continue;
            if(log=="../")
            {
                if(!s.empty())
                    s.pop();
                else 
                    continue;
            }
            else
            {
                s.push(log);
            }
        }
        return s.size();
    }
};