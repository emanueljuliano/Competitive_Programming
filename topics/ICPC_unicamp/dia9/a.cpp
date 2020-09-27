// https://codeforces.com/group/NTEJ3kWgR3/contest/267402/attachments
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"
#define pb push_back
#define s second
#define f first

typedef pair<int, int> ii;
typedef long long ll;

const int MAX = 2e5+10;

int maxi = 0;
int a[MAX];
int seg[4*MAX], lazy[4*MAX];

int build(int p=1, int l=0, int r=maxi-1){
	lazy[p] = 0;
	if(l==r) return seg[p] = a[l];
	int m = (l+r)/2;
	return seg[p] = max(build(2*p, l, m),  build(2*p+1, m+1, r));
}
void prop(int p, int l, int r){
	if(!lazy[p]) return;
	int m = (l+r)/2;
	seg[2*p] += lazy[p];
	seg[2*p+1] += lazy[p];
	lazy[2*p] += lazy[p], lazy[2*p+1] += lazy[p];
	lazy[p] = 0;
}
int query(int a, int b, int p=1, int l=0, int r=maxi-1){
	if(b<l or r<a) return 0;
	if(a<=l and r<= b) return seg[p];
	prop(p, l, r);
	int m = (l+r)/2;
	return max(query(a, b, 2*p, l , m), query(a, b, 2*p+1, m+1, r));
}
int update(int a, int b, int x, int p=1, int l=0, int r=maxi-1){
	if(b<l or r<a) return seg[p];
	if(a<=l and r<=b){
		seg[p] += x;
		lazy[p] += x;
		return seg[p];
	}
	prop(p, l ,r);
	int m = (l+r)/2;
	return seg[p] = max(update(a, b, x, 2*p, l, m),
						update(a, b, x, 2*p+1, m+1, r));
}

int main(){ _
	int n; cin >> n;
	memset(a, 0, sizeof(a));

	map<int, int> ma;
	vector<pair<int, ii>> ev, ev2;
	vector<ii> v;
	for(int i=0;i<n; i++){
		int x1,y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		ev.pb({y2, {0, i}});
		ev.pb({y1, {1, i}});
		v.pb({y2, y1});
	}
	sort(ev.begin(), ev.end());

	// compressao
	int at1 = -1, at2=-10000010; 
	for(int i=0; i<ev.size(); i++){
		if(ev[i].f != at2){
			at1++, at2=ev[i].f;
			ma[at2] = at1;
		}
		ev2.pb({at1, ev[i].s});
	}
	ev = ev2;
	maxi = ev.back().f+1;

	// intersecoes
	int at = 0;
	for(int i=0; i<ev.size(); i++){
		a[ev[i].f] = max(a[ev[i].f], at);
		if(ev[i].s.f == 0) at++;
		else at--;
		a[ev[i].f] = max(a[ev[i].f], at);
	}

	// seg
	build();
	int ans = 0;
	at = 0;
	for(int i=0; i<ev.size(); i++){
		int ind = ev[i].s.s;
		if(ev[i].s.f==0){
			at++;
			update(ma[v[ind].f], ma[v[ind].s], -1);
		}
		else{
			at--;
			update(ma[v[ind].f], ma[v[ind].s], 1);
		}
		ans = max(ans, at+query(0, maxi));
	}

	cout << ans << endl;
	exit(0);
}
