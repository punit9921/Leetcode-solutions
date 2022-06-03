class Solution {
public:
    int integerBreak(int n) {
        if(n==2)
            return 1;
        if(n==3)
            return 2;
        int two=0;
        int three=n/3;
        if(n%3==1)
        {
            three--;
            
        }
        two=(n-three*3)/2;
        return pow(3,three)*pow(2,two);
    }
};


