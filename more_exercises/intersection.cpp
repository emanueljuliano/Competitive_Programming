#include <bits/stdc++.h>

using namespace std;
const int MAX = 10100;


int main(){ ios_base::sync_with_stdio(0);cin.tie(0);
	int t, n, m, a, q, d, x, y; 
	set <int> se[MAX];
	vector<int> inter;

	cin >> t;
	while(t--){
		cin >> n;
		for(int i=0; i<=n; i++) se[i].clear();
		for(int i=0; i<n; i++){
			cin >> m;
			for(int j=0; j<m; j++){
				cin >>a;
				se[i].insert(a);
			}
		}
		cin >> q;
		for(int i=0; i<q; i++){
			cin >> d >> x>> y;
			x--; y--;
			inter.resize(0);
			set_intersection(se[x].begin(), se[x].end(), se[y].begin(), se[y].end(),
							inserter(inter, inter.begin()));
			if(d==1)
				cout << inter.size() << endl;
			else if(d==2)
				cout << se[x].size() + se[y].size() - inter.size() << endl;
		}
	}
}
