class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(right>left)
            return (rangeBitwiseAnd(left/2,right/2)<<1);
        else
            return left;
    }
};