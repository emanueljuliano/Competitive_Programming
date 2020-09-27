#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define s second
#define f first

typedef long long ll;
typedef pair<int, int> ii;

vector<ii> v;
int pd[2020][2020];
int n;


int knap(int x, int i){
	if(i==n) return 0;
	if(pd[x][i]!=-1) return pd[x][i];
	if(x<v[i].f) return pd[x][i] = knap(x, i+1);
	return pd[x][i] = max(v[i].s + knap(x-v[i].f, i+1), knap(x, i+1));
}

int main(){ _
	memset(pd, -1, sizeof(pd));
	int s; cin >> s >> n;
	for(int i=0; i<n; i++){
		int a, b; cin >> a >> b;
		v.pb({a, b});
	}

	cout << knap(s, 0) << endl;

	exit(0);
}
