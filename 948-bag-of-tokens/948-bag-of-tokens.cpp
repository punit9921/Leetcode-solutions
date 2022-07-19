class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int i=0;
        int j=tokens.size()-1;
        int points=0,res=0;
        sort(begin(tokens),end(tokens));
        while(i<=j)
        {
            if(tokens[i]<=power)
            {
                power-=tokens[i++];
                res=max(res,++points);
            }
            else if(points>0)
            {
                points--;
                power+=tokens[j--];
            }
            else
                break;
        }
        return res;
    }
};