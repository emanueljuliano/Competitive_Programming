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

const int MAX = 2e5 + 10;
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
	int cs = 1;
	while(true){
		cin >> n; if(!n) break;
		if(cs != 1) cout << endl;
		cout << "Case " << cs++ << ":" << endl;
		for(int i=0;i <n; i++) cin >> v[i];
		build();
		string s;
		while(true){
			cin >> s; if(s=="END") break;
			int x, y; cin >> x >> y; x--;
			if(s[0]=='M') cout << query(x, y-1) << endl;
			else update(x, y);
		}
	}

	exit(0);
}
