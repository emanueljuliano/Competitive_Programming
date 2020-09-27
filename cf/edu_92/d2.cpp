#include<bits/stdc++.h>

#define f first
#define s second
#define pb push_back


using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
vector<int>valores;
ll pd [5000000][5];
int n;
int k;
int z;
ll dp (ll x, ll y, ll w, int f)
{
	if(x==n-1){return 0;}
	if(w==0){return 0;}
	//if(pd[x][f]!=-1) return pd[x][f];
	ll pra_frente=0;
	ll pra_tras=0;

	if(x<n-1){pra_frente=valores[x+1]+dp(x+1,y,w-1,1);}
	if(x>0 and y>0 and f==1){pra_tras=valores[x-1]+dp(x-1,y-1,w-1,0);}

	return pd[x][f]=max(pra_frente,pra_tras);
}

int main ()
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	int t;
	cin>>t;
	while(t!=0)
	{
		t--;
		cin>>n>>k>>z;
		for(int i=0; i<=n; i++) for(int j=0; j<5; j++) pd[i][j] = -1;
		valores.clear();
		valores.resize(n);
		for(int i=0;i<n;i++)
		{
			cin>>valores[i];
		}
		cout<<dp(0,z,k,1)+valores[0]<<endl;
	}
	return 0;


}
