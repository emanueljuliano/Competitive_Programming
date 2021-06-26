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
	int n; cin >> n;
	vector<ii> v(n);
	for(auto &[a, b] : v) cin >> a >> b;
	sort(v.begin(), v.end(), greater<>());
	int mini = v[0].s;
	int it = 1;
	bool can = true;
	while(it<n and v[it].f>mini){
		if(v[it].s>mini) can = false;
		else mini = v[it].s;
		it++;
	}

	if(can) cout << v[0].s << endl;
	else cout << v[0].f << endl;
	
	
	
	exit(0);
}
