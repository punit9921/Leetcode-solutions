class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
       long long int sum=0;
        int n=cardPoints.size();
        for(int i=n-k;i<n;i++)
        {
           sum+=cardPoints[i];
        }
       long long int ans=sum;
        for(int i=0;i<k;i++)
        {
            sum-=cardPoints[n-k+i];
            sum+=cardPoints[i];
            ans=max(ans,sum);
        }
        return (int)ans;
    }
};