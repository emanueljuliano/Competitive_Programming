#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;
typedef long double ld;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;


int main(){ _
	int n, k; cin >> n >> k;
	vector<ld> v(n);
	for(auto &i : v) cin >> i;
	cout << setprecision(7) << fixed;
	if(k==1){
		for(int i=0;i <n; i++) cout << ((ld)100/n) << " ";
		cout << endl;
		exit(0);
	}

	vector<ld> ans(n);
	for(int i=0;i <n; i++){
		ld at = 1;
		ld sum = v[i];
		ans[i] = v[i];
		for(int j=1; j<=n-k; j++){
			sum += v[((i-j)+n)%n];
			at = at*(n-j-k+1)/(n-j-1);
			//cout << i << " " << sum << " " << at << endl;
			ans[i] += sum*at;
		}
	}

	ld tot = 0;
	for(auto u : ans) tot += u;
	tot/=100;
	for(auto u : ans) cout << u/tot << " ";
	cout << endl;
	
	
	
	exit(0);
}
