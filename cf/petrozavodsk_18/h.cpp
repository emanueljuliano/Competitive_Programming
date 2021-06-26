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

int main(){ _
	int k, n, m; cin >> k >> n >> m;
	vector<int> v, a(k);
	for(int i=0;i <k; i++){
		cin >> a[i];
		if(a[i]==-1){
			if(i==0) a[i] = 1;
			else a[i] = a[i-1];
		}
	}
	vector<int> aux = a;
	sort(aux.begin(), aux.end());
	if(a != aux) return cout << -1 << endl, 0;
	if(n<k) return cout << -1 << endl, 0;
	int r = k-1;
	for(int i=m; i>a[0]; i--){
		while(r>0 and a[r]>=i) r--;
		int at = 0;
		while(at<=r and int(v.size())<n-k) v.pb(i), at++;
		if(v.size()==n-k) break;
	}

	for(auto u : a) v.pb(u);
	if(v.size()<n) return cout << -1 << endl, 0;
	for(auto u : v) cout << u << " ";
	cout << endl;
	
	
	
	exit(0);
}
