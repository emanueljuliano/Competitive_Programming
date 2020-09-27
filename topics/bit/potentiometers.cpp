#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;

const int MAX = 1e5+10;

int n;
int bit[MAX];
vector<int> v;

void build() {
	bit[0] = 0;
	for (int i = 1; i <= n; i++) bit[i] = v[i - 1];

	for (int i = 1; i <= n; i++) {
		int j = i + (i & -i);
		if (j <= n) bit[j] += bit[i];
	}
}

void update(int p, int x) {
	for (; p <= n; p += p & -p) bit[p] += x;
}

int pref(int p) {
	int ret = 0;
	for (; p; p -= p & -p) ret += bit[p];
	return ret;
}

int query(int a, int b) {
	return pref(b) - pref(a - 1);
}

int main(){ _
	int cs = 1;
	while(true){
		cin >> n; if(!n) break;	
		cout << "Case " << cs << ":" << endl; cs++;
		
		v.resize(n);
		for(auto &i: v){
			cin>> i;
		}

		build();
		
		while(true){
			string s; cin >> s; 
			if(s=="END") break;
			int a, b; cin >> a >> b;
			if(s[0]=='S') update(a, b-query(a, a));
			else cout << query(a, b) << endl;
		}
	}
	exit(0);
}
