class Solution {
public:
    int getSum(int a, int b) {
       // if(a && b)
       //    return getSum(a^b, (unsigned int)(a&b) << 1);
       // else 
       //     return a|b;
        while(b>0)
        {
            a++;
            b--;
        }
        while(b<0)
        {
            a--;
            b++;
        }
        return a;
    }
};