#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MAX = 1e5+10;
const int bsz = sqrt(MAX);

pair<int, int> ans[bsz];

int main(){ _
	int n; cin >> n;

	vector<int> v(n);
	for (auto &i : v) cin >> i;	
	
	vector<int> crec(n), dec(n), f(n);

	crec[n-1] = dec[n-1] = f[n-1] = 1;
	for (int i=n-2; i+1; i--) {
		if (v[i] > v[i+1]) dec[i] = 1 + dec[i+1], crec[i] = 1;
		else dec[i] = 1, crec[i] = 1 + crec[i+1];
		f[i] = max(crec[i], dec[i]);
	}
	
	auto sim = [&](int i){
		int j = 0;
		int a = 0, b = 0;
		while (j<n) {
			a++;
			if(f[j] >= i) j+=f[j];
			else {
				b += min(i, n-j) - f[j];
				j += i;
			}
		}
		return pair<int, int>(a, b);
	};

	for(int i=2; i<min(n+1, bsz); i++){
		ans[i] = sim(i);
	}

	int q; cin >> q;
	while(q--){
		int minrun; cin >> minrun;
		if(minrun < bsz) {
			auto [a, b] = ans[minrun];
			cout << a << " " << b << endl;
		}
		else {
			auto [a, b] = sim(minrun);
			cout << a << " " << b << endl;
		}
	}
	
	exit(0);
}
