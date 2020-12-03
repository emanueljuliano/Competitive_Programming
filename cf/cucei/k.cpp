#include <bits/stdc++.h>

using namespace std;

//#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int n, q=0;
int query(int a, int b, int c){
	q++;
	if(q==7777) while(true){}
	cout << "? " << a << " " << b << " " << c << endl;
	int k; cin >> k;
	return k;
}
int solve(vector<int> v, int pos, int mini){
	shuffle(v.begin(), v.end(), rng);
	vector<int> l, r;
	for(int i=1; i<v.size(); i++){
		int u = v[i];
		int k = query(v[0],  u, mini);
		if(k == u) l.pb(u);
		else r.pb(u);
	}
	if(l.size()+pos < n/2) return solve(r, pos+l.size()+1, mini);	
	else if(l.size()+pos > n/2) return solve(l, pos, mini);
	return v[0];
}

int main(){
	cin >> n;

	int mini = 1, maxi = 2;
	for(int i=3; i<=n; i++){
		int k = query(i,  mini, maxi);
		if(k==mini) mini = i;
		if(k==maxi) maxi = i;
	}
	
	vector<int> v;
	for(int i=1; i<=n; i++) if(i!=mini) v.pb(i);
	int ans = solve(v, 1, mini);
	cout << "! " << ans << endl;
	exit(0);
}
