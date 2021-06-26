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
	vector<int> a(n), b(n), c(n);
	for(auto &i : a) cin >> i, i--;	
	for(auto &i : b) cin >> i, i--;	
	for(auto &i : c) cin >> i, i--;	
	vector<int> v(n);
	int at = 0;
	ll ans =0;
	for(int i=0;i <n; i++){
		if(v[a[i]]++ == 0) ans += at;
		if(v[b[i]]++ == 0) ans += at;
		if(v[c[i]]++ == 0) ans += at;
		
		if(v[a[i]] == 3) at++;
		if(a[i]!=b[i] and v[b[i]] == 3) at++;
		if(b[i]!=c[i] and a[i]!=c[i] and v[c[i]] == 3) at++;
	}

	cout << ans << endl;

	exit(0);
}
