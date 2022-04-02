class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
      int j=0;
        stack<int>s;
        for(auto it:pushed)
        {
            s.push(it);
            while(!s.empty() and s.top()==popped[j])
            {
                s.pop();
                j++;
            }
        }
        return s.empty();
    }
};