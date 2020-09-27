#include <bits/stdc++.h>
using namespace std;
#define pi 3.14159265359
#define int long long
#define pii pair<int,int>
const int mod=1e9+7;

int dx[]={-1, 0, 1, 0};
int dy[]={0, -1, 0, 1};

void mul(int x[2][2],int y[2][2])
{
	int res[2][2];

	res[0][0]=((x[0][0]*y[0][0])%mod + (x[0][1]*y[1][0])%mod )%mod;
	res[0][1]=((x[0][0]*y[0][1])%mod + (x[0][1]*y[1][1])%mod )%mod;
	res[1][0]=((x[1][0]*y[0][0])%mod + (x[1][1]*y[1][0])%mod )%mod;
	res[1][1]=((x[1][0]*y[0][1])%mod + (x[1][1]*y[1][1])%mod )%mod;

	for(int i=0;i<2;i++) for(int j=0;j<2;j++) x[i][j]=res[i][j];
}

void power(int x[][2],int p)
{
	int res[2][2]={{1,0},{0,1}};
	while(p>0)
	{
		if(p&1)
			mul(res,x);

		mul(x,x);
		p=p>>=1;
	}
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
			x[i][j]=res[i][j];
	}
}


int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin>>t;
	while(t--)
	{
		int a,n;
		cin>>a>>n;

		a=(a%mod+mod)%mod;
		n=abs(n);

		int x[2][2]={{0,1},{mod-1,a}};
		if(n==0)
		{
			cout<<2<<"\n"; continue;
		}
		else if(n==1)
		{
			cout<<a<<"\n"; continue;
		}

		power(x,n-1);

		int ans=((2*x[1][0])%mod + a*(x[1][1])%mod)%mod;
		cout<<ans<<"\n";
	}
}
