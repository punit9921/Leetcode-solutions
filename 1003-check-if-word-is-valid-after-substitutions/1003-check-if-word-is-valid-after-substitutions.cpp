class Solution {
public:
    bool isValid(string s) {
        if(s.size()%3!=0)
            return false;
        stack<char>st;
        for(auto i:s)
        {
            if(i!='c')
                st.push(i);
            else
            {
                if(st.size()>=2)
                {
                    if(st.top()=='b')
                    {
                        st.pop();
                         if(st.top()=='a')
                             st.pop();
                        else
                            return false;
                    }
                    else
                        return false;
                }
            }
        }
        if(st.size()==0)
            return true;
        else
            return false;
    }
};