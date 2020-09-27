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


int main(){ _
	int n; cin >> n;
	vector<int> dg(n, 0);
	vector<ii> v;
	for(int i=0; i<n-1; i++){
		int a, b; cin >> a >> b; a--; b--;
		dg[a]++;
		dg[b]++;
		v.pb({a, b});
	}
	int it1 = 0, it2=n-2;
	for(int i=0;i <n-1; i++){
		if(dg[v[i].f]==1 or dg[v[i].s]==1){cout << it1 << endl; it1++;}
		else {cout << it2 << endl; it2--;}
	}
	
	exit(0);
}
