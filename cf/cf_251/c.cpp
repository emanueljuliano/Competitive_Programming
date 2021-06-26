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
	int n, k, p; cin >> n >> k >> p;
	vector<int> ev, odd;
	for(int i=0;i <n; i++){
		int a; cin >> a;
		if(a%2==0) ev.pb(a);
		else odd.pb(a);
	}

	if(int(odd.size()) < k-p) return cout << "NO" << endl, 0;
	int res = odd.size()-(k-p);
	if(res%2 == 1) return cout << "NO" << endl, 0;
	if(res/2 + int(ev.size()) < p) return cout << "NO" << endl, 0;

	cout << "YES" << endl;
	vector<vector<int>> part(k);
	for(int i=0;i <k-p; i++) part[i].pb(odd.back()), odd.pop_back();
	int at = 0;
	for(int i=k-p; i<k; i++){
		if(!odd.size()) break;
		part[i].pb(odd.back()); odd.pop_back();
		part[i].pb(odd.back()); odd.pop_back();
		at++;
	}
	for(int i=k-p+at; i<k; i++){
		if(!ev.size()) break;
		part[i].pb(ev.back()); ev.pop_back();
		at++;
	}
	while(odd.size()) part[0].pb(odd.back()), odd.pop_back();
	while(ev.size()) part[0].pb(ev.back()), ev.pop_back();

	for(int i=0;i <k; i++){
		cout << part[i].size() << " ";
		for(auto u : part[i]) cout << u << " ";
		cout << endl;
	}
	
	
	exit(0);
}
