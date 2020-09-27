#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 1e5+10;

namespace seg2{
	int seg[2*MAX];
	int n, *v;	
	void build(int n2, int *v2){
		n = n2; v = v2;
		for(int i=0; i<n; i++) seg[i+n] = v[i];
		for(int i=n-1;i; i--) seg[i] = max(seg[2*i], seg[2*i+1]);
	}
	int query(int a, int b){
		int ret = -INF;
		for(a+=n, b+=n; a<=b; ++a/=2, --b/=2){
			if(a%2==1) ret = max(ret, seg[a]);
			if(b%2==0) ret = max(ret, seg[b]);
		}
		return ret;
	}
}

namespace seg1{
	int seg[2*MAX];
	int n, *v;	
	void build(int n2, int *v2){
		n = n2; v = v2;
		for(int i=0; i<n; i++) seg[i+n] = v[i];
		for(int i=n-1;i; i--) seg[i] = min(seg[2*i], seg[2*i+1]);
	}
	int query(int a, int b){
		int ret = INF;
		for(a+=n, b+=n; a<=b; ++a/=2, --b/=2){
			if(a%2==1) ret = min(ret, seg[a]);
			if(b%2==0) ret = min(ret, seg[b]);
		}
		return ret;
	}
}


namespace hld{
	vector<ii> g[MAX];
	int pos[MAX], sz[MAX];
	int sobe[MAX], pai[MAX];
	int h[MAX], v[MAX], t;

	void build_hld(int k, int p=-1, int f=1){
		v[pos[k] = t++]=sobe[k]; sz[k] = 1;
		for(auto& i : g[k]) if(i.f!=p){
			sobe[i.f] = i.s; pai[i.f] = k;
			h[i.f] = (i==g[k][0] ? h[k] : i.f);
			build_hld(i.f, k, f); sz[k] += sz[i.f];
			if(sz[i.f] > sz[g[k][0].f] or g[k][0].f==p) swap(i, g[k][0]);
		}	
		if(p*f==-1) build_hld(h[k]=k, -1, t=0);
	}
	void build(int root=0){
		t = 0;
		build_hld(root);
		seg1::build(t, v);
		seg2::build(t, v);
	}
	int qmin(int a, int b){
		if(a==b) return INF;
		if(pos[a]<pos[b]) swap(a, b);
		if(h[a]==h[b]) return seg1::query(pos[b]+1, pos[a]);
		return min(seg1::query(pos[h[a]], pos[a]), qmin(pai[h[a]], b));
	}
	int qmax(int a, int b){
		if(a==b) return -INF;
		if(pos[a]<pos[b]) swap(a, b);
		if(h[a]==h[b]) return seg2::query(pos[b]+1, pos[a]);
		return max(seg2::query(pos[h[a]], pos[a]), qmax(pai[h[a]], b));
	}

}

int main(){ _
	int n; cin >> n;
	for(int i=0;i <n-1; i++){
		int a, b, c; cin >> a >> b >> c; a--; b--;
		hld::g[a].pb({b, c}); hld::g[b].pb({a, c});
	}
	hld::build();
	int k; cin >> k;
	while(k--){
		int a, b; cin >> a >> b; a--; b--;
		cout << hld::qmin(a, b) << " " << hld::qmax(a, b) << endl;
	}


	exit(0);
}
