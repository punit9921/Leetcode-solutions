class Solution {
public:
  int DigitSum(int n) {
        int res = 0;
        while (n) {
            int rem = n % 10;
            res += rem;
            n /= 10;
        }
        return res;
    }
    int maximumSum(vector<int>& nums) {
        priority_queue<int> equal_sum[82];
        for (auto n : nums) {
            equal_sum[DigitSum(n)].push(n);
        }
        int sum = -1;
        for (int i = 0; i < 82; i++) {
            if (equal_sum[i].size() >= 2) {
                int top = equal_sum[i].top();
                equal_sum[i].pop();
                top += equal_sum[i].top();
                sum = max(sum, top);
            }
        }
        return sum;
    }
};