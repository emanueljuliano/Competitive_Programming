#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MAX = 1e5+10;
const int magic = 100;

vector<tuple<int, int, int>> v[magic][MAX];
priority_queue<pair<int, int>> pq[magic+5];
priority_queue<pair<int, int>> apagados[magic+5];

int main(){ _
	string s; cin >> s;
	int n = s.size();
	vector<int> t(n);
	int q; cin >> q;
	for (int j=1; j<=q; j++) {
		int i, a, k; cin >> i >> a >> k; i--;
		char c; cin >> c;
		
		if (a>=magic) {
			for (int l=0; l<=k; l++) 
				s[i+l*a] = c, t[i+l*a] = j;
		}
		else {
			v[a][i].push_back({0, j, c});
			v[a][i+k*a].push_back({1, j, c});
		}
	}
	
	for (int i=1; i<magic; i++) {
		for (int j=0; j<n; j++) {
			for (auto [flag, tt, c] : v[i][j]) {
				if(!flag) pq[j%i].push({tt, c});
				else apagados[j%i].push({tt, c});
			}
			if(!pq[j%i].empty()){
				auto [tt, c] = pq[j%i].top();
				if(tt>t[j]) t[j] = tt, s[j] = c;
			}
			while(pq[j%i].size() and apagados[j%i].size() 
				and pq[j%i].top() == apagados[j%i].top()) 
					pq[j%i].pop(), apagados[j%i].pop();
		}
	}

	cout << s << endl;

	
	exit(0);
}
