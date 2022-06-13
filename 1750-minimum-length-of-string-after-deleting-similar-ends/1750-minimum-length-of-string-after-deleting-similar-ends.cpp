class Solution {
public:
    int minimumLength(string s) {
       int n=s.size();
        int start=0,end=s.size()-1;
            while(start<end)
            {
                if(s[start]!=s[end])
                    break;
                while(start<=end and s[start]==s[end])
                    start++;
                while(start<=end and s[start-1]==s[end])
                    end--;
            }
        return end-start+1;
    }
};