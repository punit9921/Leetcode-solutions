class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(begin(tokens),end(tokens));
        int i=0,j=tokens.size()-1;
        int res=0;
        int points=0;
        while(i<=j)
        {
            if(power>=tokens[i])
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