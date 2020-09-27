#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define mp make_pair
//#define faz(a,b,c) (mp((a),mp((b),(c))))
//#define faz(a,b,c) a][b][c

#define MAX 14

#define faz(a,b,c) ((a)+((b)<<MAX)+((c)<<(2*MAX)))



pair<int, pair <int, int> > faz2 (int a, int b, int c)
{
	return (mp((a),mp((b),(c))));
}

//desliga!


#define nega(x,b) ((x)&(~(1<<(b))))
int nega2(int x, int b)
{
	return ((x)&(~(1<<(b))));
}


typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

string sadj[MAX];
int adj[MAX][MAX];

unordered_map<int,int>dp;
//map<pair<int, pair<int,int> >,ll >dp;
		//padrao     set, v

//ll dp[1<<MAX][1<<MAX][MAX];

int n;




void calcdp()
{
	for (int i=0; i<n; i++)
		dp[faz(0,(1<<i),i)] = 1;
		//padrao,  set, v
	for (int i=1; i < (1<<n); i++) //set
	{
		//cout << "i = " << i << " n = " << n << endl;
		int compr = 0;
		for (int j=0; j<n; j++)
			if (i & (1<<j))
				compr++;
		if (compr == 1)
			continue;

		for (int j=0; j<(1<<(compr-1)); j++) //string
		{
			//cout << "j = " << j << endl;
			for (int k=0; k<n; k++)
			{
				if (!(i & (1<<k))) //se k nao pertence a i, segue
					continue;
				//cout << "analisando vert " << k << endl;
				//dp[faz(j,i,k)] = 0;
				for (int l=0; l<n; l++)
				{

					//cout << l << " eh diferente " << k << endl;
					if (!(i&(1<<l))) // l nao pertence)
						continue;
					if (l==k) 
						continue;
					//cout << l << " pertence ao conjunto" << endl;
					//cout << "compararei valores " << adj[k][l] << " e " << (j&(1<<(compr-2))) << endl;
					int t = 0;
					if ((j&(1<<(compr-2))))
						t = 1;
					if (adj[k][l] == t) //a adj casa com o esperado
					{
						//cout << j << " e " << k << " sao vizinhos, somando " << dp[faz(nega(j,compr-2),nega(i,k),l)] << endl;
						dp[faz(j,i,k)] += dp[faz(nega(j,compr-2),nega(i,k),l)];
					}
				}
			}
		}
	}
}

int main(){ _

	cin >> n;

	for (int i=0; i<n; i++)
		cin >> sadj[i];

	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			adj[i][j] = sadj[i][j]-'0';

	//cout << "vou calcular\n";

	calcdp();

	for (int i=0; i<(1<<(n-1));i++)
	{
		if (i) 
			cout << " ";
		ll resp = 0;
		for (int j=0; j<n; j++)
			resp+=dp[faz(i,(1<<n)-1,j)];
		cout << resp;
	}
	cout << endl;

	int at = 0;
	for(auto x : dp)
		at = x.f;
	cout << at << " ue " << endl;
	exit(0);
}

