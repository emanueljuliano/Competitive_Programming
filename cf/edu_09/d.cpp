#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	int n, m; cin >> n >> m;
	vector<int> v(m+1), w;
	for (int i=0;i <n; i++) {
		int a; cin >> a;
		w.push_back(a);
		if (a <= m) v[a]++;
	}
	vector<int> ans(m+1);
	int maxi = 0, pos = 1;
	for (int i=1; i<=m; i++) {
		for (int j=i; j<=m; j+=i) ans[j]+=v[i];
		if (ans[i] > maxi) maxi = ans[i], pos = i;
	}

	cout << pos << " " << maxi << endl;
	for (int i=0; i<n; i++) {
		if (pos % w[i] == 0) cout << i+1 << " ";
	}
	cout << endl;

	
	
	
	exit(0);
}
