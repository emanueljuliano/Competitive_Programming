#include <bits/stdc++.h>
using namespace std;

#define N 5010
int a[N], b[N];
long double c[N], d[N];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d %d", &a[i], &b[i]);
		double w;
		scanf("%lf", &w);
		c[i] = log(w);
	//	cout << c[i] << endl;
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			d[b[j]] = max(d[b[j]], d[a[j]] + c[j]);
		}
	}
	int flag = 0;
	for (int i = 1; i <= m; ++i)
	{
		if (d[b[i]] < d[a[i]] + c[i])
			flag = 1;
	}
	puts(flag? "inadmissible": "admissible");
	return 0;
}
