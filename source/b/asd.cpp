#include <bits/stdc++.h>
using namespace std;
int n, m, a[550] = {0}, b[550][550] = {0},ans=0;
int main()
{
	cin >> n >> m;
	int t = 0;
	for (int i = 1; i <= n; i++)
	{
		int t = 0;
		for (int j = 1; j <= m; j++)
		{
			cin >> t;
			a[i] += t;
			a[i] <<= 1;
		}
		a[i] >>= 1;
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			b[i][j] = b[j][i] = __builtin_popcount(a[i] & a[j]);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		int mx=-1;
		for (int j = 1; j <= n; j++)
		{
			if(b[i][j]>mx)
			{
				mx=b[i][j];
			}
		}
		b[i][0]=mx;
	}	
	// memset(b, 0, sizeof(b));
	for (int t = 1; t <= m; t++)
	{
		int sum=0;

		if (a[1] & 1 << t - 1)
			continue;
		a[1] = a[1] | 1 << t - 1;

		for (int j = 2; j <= n; j++)
		{
			b[1][j] =b[j][1]= __builtin_popcount(a[1] & a[j]);
			if(b[1][j]<b[j][0]){
				b[1][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			if(b[1][i]){
				sum++;
			}
		}
		if(sum>ans){
			ans=sum;
		}
		a[1] = a[1] & ~(1 << t - 1);
	}
	cout<<ans;
	return 0;
}
