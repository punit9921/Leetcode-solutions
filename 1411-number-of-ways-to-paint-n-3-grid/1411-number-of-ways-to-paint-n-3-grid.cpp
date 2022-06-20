class Solution {
public:
    const int mod=1e9+7;
    int numOfWays(int n) {
       long int a121=6;
       long int a123=6;
       long long int b121,b123;
        for(int i=1;i<n;i++){
            b121=a121*3 + a123*2;
            b123=a121*2 + a123*2;
            a121=b121%mod;
            a123=b123%mod;
        }
        return (a121+a123)%mod;
    }
};