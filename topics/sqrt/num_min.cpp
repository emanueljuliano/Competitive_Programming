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

const int MAX = 1e5+10;
const int bsz = sqrt(MAX) + 1;

int v[MAX];
int block[bsz];
int bmin[bsz];
int n, m;

void build(){
	for(int i=0; i<n/bsz+1; i++){
		int l=i*bsz, r=min(l+bsz, n);
		block[i] = 0, bmin[i] = INF;
		for(int j=l; j<r; j++) bmin[i] = min(bmin[i], v[j]);
		for(int j=l; j<r; j++) block[i] += v[j] == bmin[i];
	}
}
void update(int i, int x){
	v[i] = x;
	int l = i/bsz, r=min(l*bsz+bsz, n);
	bmin[l] = INF, block[l] = 0;
	for(int j=l*bsz; j<r; j++) bmin[l] = min(bmin[l], v[j]);
	for(int j=l*bsz; j<r; j++) block[l] += bmin[l] == v[j];
}
ii query(int l, int r){
	int l2 = (l+bsz-1)/bsz*bsz, r2 = r/bsz*bsz;
	int ret = 0, mini = INF;
	if(r<l2){
		for(int i=l; i<=r; i++) mini = min(mini, v[i]);
		for(int i=l; i<=r; i++) ret += mini==v[i];
		return {mini, ret};
	}	
	for(int i=l; i<min(r+1, l2); i++) mini = min(mini, v[i]);
	for(int i=l2; i<r2; i+=bsz) mini = min(mini, bmin[i/bsz]);
	for(int i=r2; i<=r; i++) mini = min(mini, v[i]);
	
	for(int i=l; i<min(r+1, l2); i++) ret += mini == v[i];
	for(int i=l2; i<r2; i+=bsz) if(bmin[i/bsz] == mini) ret += block[i/bsz];
	for(int i=r2; i<=r; i++) ret += mini == v[i];
	
	return {mini, ret};
}

int main(){ _
	cin >> n >> m;
	for(int i=0;i <n; i++) cin >> v[i];
	build();
	while(m--){
		int flag, l, r; cin >> flag >> l >> r;
		if(flag==1) update(l, r);
		else{
			ii q = query(l, r-1);
			cout << q.f << " " << q.s << endl;
		}
	}
	
	
	exit(0);
}
