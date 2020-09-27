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


int main(){ _
	int n, m; cin >> n >> m;

	vector<int> id(n);
	for(int i=0;i <n; i++) id[i] = i;
	function<int(int)> f = [&](int p){
		if(p==id[p]) return p;
		return id[p] = f(id[p]);
	};
	
	int ans = 0;
	vector<int> ar(m, -1);
	for(int i=0;i <n; i++){
		int k; cin >> k;
		for(int j=0; j<k; j++){
			int a; cin >> a; a--;
			if(ar[a]==-1) ar[a] = i;
			else if(f(ar[a]) != f(i)){
				ans++;
				id[f(ar[a])] = f(i);
			}
		}
	}
	cout << ans << endl;

	exit(0);
}
