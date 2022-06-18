class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
         
        
      long long  int sum=0;
        for(int i=shifts.size()-1;i>=0;i--)
        {
            sum+=shifts[i];
            s[i] = (((s[i] - 'a') + sum) % 26) + 'a';
        }
       
        return s;
    }
};