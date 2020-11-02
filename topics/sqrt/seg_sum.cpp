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

const int MAX = 1e5 + 10;
const int bsz = sqrt(MAX) + 1;

int v[MAX];
ll block[bsz];
int n, m;

void build(){
	for(int i=0; i<bsz; i++) block[i] = 0;
	for(int i=0;i <n; i++) block[i/bsz] += v[i];
}
void update(int i, int x){
	block[i/bsz] += x-v[i], v[i]=x;
}
ll query(int l, int r){
	int l2 = (l+bsz-1)/bsz * bsz, r2 = r/bsz * bsz;
	ll ret = 0;
	if(r<l2){
		for(int i=l; i<=r; i++) ret += v[i];
		return ret;
	}	
	for(int i=l; i<min(r+1, l2); i++) ret += v[i];
	for(int i=l2; i<r2; i+=bsz) ret += block[i/bsz];
	for(int i=r2; i<=r; i++) ret += v[i];
	return ret;
}

int main(){ _
	cin >> n >> m;
	for(int i=0;i <n; i++) cin >> v[i];
	build();
	while(m--){
		int flag, l, r; cin >> flag >> l >> r;
		if(flag==1) update(l, r);
		else cout << query(l, r-1) << endl;
	}
	
	
	exit(0);
}
