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
int dp[MAX][MAX];
int n, p;
vector<int> good, v;

int solve(int i, int t){
	if(i<0 and t==0) return 0;
	if((i<0) != (t==0)) return -INF;
	
	int &ret = dp[i][t];
	if(ret != -1) return ret;

	int lat = l[v[i]], rat = r[v[i]];
	ret = rat-lat + solve(i-1, t-1);
	for(int j=i-1; j>=0; j--){
		lat = max(lat, l[v[j]]);
		rat = min(rat, r[v[j]]);
		if(lat>=rat) break;
		ret = max(ret, rat-lat + solve(j-1, t-1));
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
	
	memset(dp, -1, sizeof dp);
	int ans = 0;
	for(int t=max(1, p-int(good.size())); t<=p; t++){
		ans = max(ans, solve(int(v.size())-1, t) + suf[p-t]);
	}
	cout << ans << endl;
	
	
	exit(0);
}
