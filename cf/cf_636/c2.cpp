#include <bits/stdc++.h>
#define f first
#define s second
#define INF 0x3f3f3f3f
#define EPS 1e-9
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int sig(int x){
	if(x > 0) return 1;
	return -1;
}

ii solve(int pos, vi &v){
	ii res = {1, v[pos]};
	int p = sig(v[pos]), last = pos;
	for(int i = pos + 1; i < v.size(); i++){
		if(sig(v[i]) == p && v[i] > v[last]){
			res.s += v[i] - v[last];
			last = i;
		}
		if(sig(v[i]) != p){
			res.f++;
			res.s += v[i];
			p *= -1;
			last = i;
		}
	}
	return res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); 
	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		vi v(n);
		for(int i = 0; i < n; i++)
			cin >> v[i];
		int flag = 0;
		ii best = {0, 0};
		for(int i = 0; i < n && flag != 3; i++){
			if(v[i] < 0 && !(flag & 1)){
				best = max(best, solve(i, v));
				flag |= 1;
			}
			if(v[i] > 0 && !(flag & 2)){
				best = max(best, solve(i, v));
				flag |= 2;
			}
		}
		cout << best.s << endl;
	}
	return 0;
}
