class Solution {
public:
     bool help(vector<int>&a,int n,vector<int> &subset,vector<int> &vis,int sum,int start,int end,int k)
{
	if(subset[start]==sum)
	{
		if(start==k-2)
		return true;
		
		return help(a,n,subset,vis,sum,start+1,n-1,k);
	}
	for(int i=end;i>=0;i--)
	{
		if(vis[i])
		continue;
		int s=subset[start]+a[i];
		if(s<=sum)
		{
			vis[i]=1;
			subset[start]+=a[i];
			bool flag=help(a,n,subset,vis,sum,start,i-1,k);
			vis[i]=0;
			subset[start]-=a[i];
			if(flag)
			return true;
		}
	}
	return false;
}
    bool canPartitionKSubsets(vector<int>& a, int k) {
        int n=a.size();
        if(n<k)
{
	return false;
}
if(k==1)
{return true;
}
int sum=0;
for(int i=0;i<n;i++)
sum+=a[i];
if(sum%k!=0)
{
	return false;
}

sum=sum/k;
vector<int> vis(n,0);
vector<int> subset(k,0);

subset[0]=a[n-1];
vis[n-1]=1;

return help(a,n,subset,vis,sum,0,n-1,k);
// cout<<"YES";
// else
// cout<<"NO";
    }
};