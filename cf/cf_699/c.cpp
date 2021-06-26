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
	int t; cin >> t;
	while(t--){
		int n, m; cin >> n >> m;
		vector<int> a(n), b(n), c(m);
		for(auto &i : a) cin >> i, i--;
		for(auto &i : b) cin >> i, i--;
		for(auto &i : c) cin >> i, i--;

		vector<int> v(n);
		vector<vector<int>> dif(n);
		set<int> colors;
		for(auto u : b) colors.insert(u);
		for(int i=0;i <n; i++)
			if(b[i]!=a[i]) v[b[i]]++, dif[b[i]].pb(i);

		vector<int> w(n);
		for(int i=0; i<m; i++)
			w[c[i]]++;
		bool show = true;
		for(int i=0;i <n; i++)
			if(v[i]>w[i]) show = false;

		if(!colors.count(c.back())) show = false;
		if(!show) {cout << "NO" << endl; continue;}

		cout << "YES" << endl;
		int last=0;
		if(dif[c.back()].size()) last= dif[c.back()][0];	
		else{
			for(int i=0;i <n; i++) if(b[i]==c.back()){last = i; break;}
		}
		for(auto u : c){
			if(dif[u].size()) cout << dif[u].back()+1 << " ", dif[u].pop_back();
			else cout << last+1 << " ";
		}
		cout << endl;

	}
	
	
	
	exit(0);
}
