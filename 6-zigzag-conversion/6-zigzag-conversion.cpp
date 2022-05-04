class Solution {
public:
    string convert(string s, int numRows) {
        string ans[numRows];
        if(numRows==1)
            return s;
        for(int i=0;i<numRows;i++)
            ans[i]="";
        int ind=0;
        bool f=true;
        for(int i=0;i<s.size();i++)
        {
            ans[ind]+=s[i];
            if(ind==0)
                f=true;
            if(ind==numRows-1)
                f=false;
            if(f)
                ind++;
            else
                ind--;
        }
        string res="";
        for(int i=0;i<numRows;i++)
            res+=ans[i];
        return res;
    }
};
