#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef double ld;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ld eps = 1e-8;

vector<int> v;
ld k;

bool val(ld x){
	ld tot = 0;
	for(int i=0;i <v.size(); i++){
		if(v[i]<x) tot -= abs(v[i]-x);
		else tot+=abs(v[i]-x)*(1.0-k);
	}
	return tot>=0.0;
}

ld bb(ld l, ld r){
	if(abs(r-l)<eps) return l;
	ld m = (r+l)/2.0;
	if(val(m)) l = m;
	else r = m;
	return bb(l, r);
}

int main(){ _
	int n; cin >> n >> k;
	k /=100.0;
	v.resize(n);
	for(auto &i : v) cin >> i;
	sort(v.begin(), v.end());

	cout << setprecision(7) << fixed;
	cout << bb(0.0, 1e3+1) << endl;
	
	
	
	exit(0);
}
