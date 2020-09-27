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

vector<int> v;

bool val(int x){
	vector<int> c;
	int at = -1;
	int it1 = x, it2 = v.size()-1;
	for(int i=x; i<v.size(); i++){
		int aux = min(v[it1], v[it2]);
		if(v[it1] < v[it2]) it1++;
		else it2--;
		if(aux<at) return false;
		at = aux;
	}
	return true;
}

int bb(int l, int r){
	if(l==r) return l;
	int m = (l+r)/2;
	if(val(m)) r = m;
	else l = m+1;
	return bb(l, r);
}

int main(){ _
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		v.resize(n);
		for(auto &i: v) cin >> i;
		cout << bb(0, n-1) << endl;
	}
	
	
	
	exit(0);
}
