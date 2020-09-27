#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5 + 10; 

int mu[MAX];
int val[MAX];
int p2[MAX2];
int n, m;

ll comb(int x){
	return (p2[x]-1+MOD)%MOD;
}

int divi[MAX];

void crivo(int lim) {
	for (int i = 1; i <= lim; i++) divi[i] = 1;

	for (int i = 2; i <= lim; i++) if (divi[i] == 1)
		for (int j = i; j <= lim; j += i) divi[j] = i;
}

vector<int> fact(int n) {
	vector<int> v;
	if (n != divi[n]) fact(v, n/divi[n]);
	v.push_back(divi[n]);
	return v;
}

int main(){ _
	crivo(MAX);
  for (int i = 0; i < MAX; i++){
        mu[i] = 1;
        val[i] = i;
    }
    for (int i = 2; i < MAX; i++){
        if (val[i] != i) continue;
        val[i] = 1;
        mu[i] = -1;
        for (int j = i+i; j < MAX; j += i){
            val[j] /= i;
            mu[j] = -mu[j];
        }
    }
    for (int i = 2; i < MAX; i++){
        if (val[i] != 1) mu[i] = 0;
		val[i] = 0;
	}
	
	int l, r; cin >> n >> m >> l >> r;


	ll ans = 0;
	for(int i=l; i<=r; i++){
		int at=0;
		vector<int> v = fact(l);
	
	
	}
	cout << ans << endl;
	
	exit(0);
}
