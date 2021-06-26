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

const int MAX = 220;

int l[MAX], r[MAX], ord[MAX];
pair<ll, int> dp[MAX];
int n, p;
vector<int> good, v;

pair<ll, int> f(int i, ll lambda){
	if(i>=v.size()) return {0, 0};
	
	pair<ll, int> &ret = dp[i];
	if(ret.s != -1) return ret;
 	ret = {-LINF, 0};

	int lat = l[v[i]], rat = r[v[i]];
	for(int j=i; j<v.size(); j++){
		lat = max(lat, l[v[j]]);
		rat = min(rat, r[v[j]]);
		if(lat>=rat) break;
		pair<ll, int> cur = f(j+1, lambda);
		if(ret.f < cur.f+rat-lat-lambda) ret = {cur.f+rat-lat-lambda, cur.s+1};
	}
	return ret;
} 

ll alien(int t){
	ll L = 0, R = 1e5*MAX*10;
	ll ret = -INF;
	while(L<R){
		for(int i=0;i <v.size(); i++) dp[i] = {-LINF, -1};
		ll M = (R+L)/2;
		auto [at, cnt] = f(0, M);

		if(cnt>=t) ret = at+t*M, L=M+1;
		else R = M-1;
	}
	return ret;
}

int main(){ _
	cin >> n >> p;
	for(int i=0;i <n; i++){
		cin >> l[i] >> r[i];
		ord[i] = i;
	}

	sort(ord, ord+n, [&](int a, int b){
		return r[a]-l[a] < r[b]-l[b];
	});

	for(int i=0; i<n; i++){
		bool ok = false;
		for(int j=0; j<i; j++){
			if(l[ord[i]] <= l[ord[j]] and r[ord[j]] <= r[ord[i]]){
				ok = true; break;
			}
		}
		if(ok) good.pb(r[ord[i]]-l[ord[i]]);
		else v.pb(ord[i]);
	}

	sort(v.begin(), v.end(), [&](int a, int b){
		if(l[a]!=l[b]) return l[a]<l[b];
		return r[a]<r[b];
	});
	
	vector<int> suf;
	suf.pb(0);
	reverse(good.begin(), good.end());
	for(auto u : good) {
		suf.pb(u+suf.back());
	}	
	
	ll ans = 0;
	for(int t=max(1, p-int(good.size())); t<=p; t++){
		ans = max(ans, alien(t) + suf[p-t]);
	}
	cout << ans << endl;
	
	
	exit(0);
}
