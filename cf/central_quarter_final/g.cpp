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
map<pair<ii, ii>, int> mp;
vector<int> v;
int solve(int l, int r, int a, int b){
//	cout << l << " " << r << " " << a << " " << b << endl;
	if(l==r) return 0;
	if(l+1==r) return (gcd(a, b) != 1);

	pair<ii, ii> id = {{l, r}, {a, b}};
	auto it = mp.find(id);
	if(mp.end() != it) return it->s;

	vector<int> mex(r-l+3);
	
	for(int i=l;i <r; i++){
		int g, a1 = r-l+2, a2 = r-l+2;
		if(i==l){
			g = gcd(a, v[i+1]);	
			if(g!=1) a2 = solve(i+1, r, v[i+1]/g, b);
			if(a2 < r-l+2) mex[a2]++;
		}
		else if(i==r-1){
			g = gcd(v[i], b);
			if(g!=1) a1 = solve(l, i, a, v[i]/g);
			if(a1 < r-l+2) mex[a1]++;
		}
		else{
			g = gcd(v[i], v[i+1]);
			if(g!=1){	
				a1 = solve(l, i, a, v[i]/g);
				a2 = solve(i+1, r, v[i+1]/g, b);
				if((a1^a2)<r-l+1) mex[a1^a2]++;
			}
		}
	}
	for(int i=0;i <=v.size()+1; i++) if(!mex[i]) return mp[id] = i;
	return 0;
}

int main(){ _
	int n; cin >> n;
	v.resize(n);
	for(auto &i: v) cin >> i;
	
	if(solve(0, n-1, v[0], v[n-1])) cout << "Alice" << endl;
	else cout << "Bob" << endl;
	
	
	exit(0);
}
