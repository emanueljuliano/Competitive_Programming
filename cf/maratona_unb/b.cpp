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
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MAX = 4e5+10;

int divi[MAX];
vector<int> primes;
vector<vector<int>> ddiv(MAX);
vector<vector<int>> pri(MAX);

void crivo(int lim) {
	divi[1] = 1;
	for (int i = 2; i <= lim; i++) {
		if (divi[i] == 0) divi[i] = i, primes.push_back(i);
		for (int j : primes) {
			if (j > divi[i] or i*j > lim) break;
			divi[i*j] = j;
		}
	}
}

int tot(int n){
	int ret = n;
	for (auto i : pri[n]) ret -= ret / i;
	return ret;
}

int main(){ _
	crivo(MAX-5);
	
	int n; cin >> n;
	vector<ll> ans(n+1);
	ans[1]++;
	for(int i=2; i<=n; i++){
		ans[i]++;
		for(int j=2; j*i<=n; j++){
			ddiv[j*i].pb(i);
			if(divi[i]==i) pri[j*i].pb(i);
		}
		if(divi[i]==i) pri[i].pb(i);
	}
	
	for(int i=2; i<=n; i++){
		ans[1] += 2*tot(i);
		for(auto d : ddiv[i]) ans[d] += 2*tot(i/d);
	}
	
	for(int i=1; i<=n; i++) cout<< ans[i] << " ";
	cout << endl;
	
	exit(0);
}
