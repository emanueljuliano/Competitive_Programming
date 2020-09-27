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

vector<int> v;
vector<int> maxE(MAX), maxD(MAX), maxEI(MAX), maxDI(MAX);
int D[MAX];
int solve(int x){
	if(D[x]!=-1) return D[x];
	int e = maxE[x], d = maxD[x];

	if(x==0 or x==v.size()-1) return D[x] = 0;
	if(e==0 and d==v.size()-1) return D[x]= 0;

	if(v[e]<v[d]) return D[x] = 1 + solve(e);
	return D[x] = 1 + solve(d);
}

int seg[2 * MAX];
int n;

void build() {
	for (int i = n-1; i; i--) seg[i] = max(seg[2*i], seg[2*i+1]);
}

int query(int a, int b) {
	int ret = 0;
	for(a += n, b += n; a <= b; ++a /= 2, --b /= 2) {
		if (a % 2 == 1) ret = max(ret, seg[a]);
		if (b % 2 == 0) ret = max(ret, seg[b]);
	}
	return ret;
}

int main(){ _
	memset(D, -1, sizeof(D));
	int m; cin >> n >> m;
	v.pb(INF);
	for(int i=0;i <n; i++){
		int a; cin >> a; v.pb(a);
	}
	v.pb(INF);

	maxE[0] = 0;
	for(int i=1; i<=n; i++){
		int aux = i-1;
		while(v[aux] <= v[i]) aux = maxE[aux];
		maxE[i]=aux;
	}	
	maxD[n] = 0;
	for(int i=n; i>=1; i--){
		int aux = i+1;
		while(v[aux] <= v[i]) aux = maxD[aux];
		maxD[i]=aux;
	}	
	maxEI[0] = 0;
	for(int i=1; i<=n; i++){
		int aux = i-1;
		while(v[aux] < v[i]) aux = maxEI[aux];
		maxEI[i]=aux;
	}	
	maxDI[n] = 0;
	for(int i=n; i>=1; i--){
		int aux = i+1;
		while(v[aux] < v[i]) aux = maxDI[aux];
		maxDI[i]=aux;
	}
	for(int i=1; i<=n; i++) seg[i+n-1]=solve(i);
	build();

	while(m--){
		int l, r; cin >> l >> r;
		int e = maxEI[l]-1, d = maxDI[l]-1;
		
		if(r!=0){ 
			if(v[l]<v[r]) {
				swap(l, r);
				e = maxEI[l]-1, d = maxDI[l]-1;
			}
			if(l==r) cout << 0 << endl;
			else if(l<r){
				if(d<r) cout << 0 << endl;
				else cout << D[r]-D[l] << endl;
			}
			else if(l>r){
				if(e>r) cout << 0 << endl;
				else cout << D[r]-D[l] << endl;
			}
		}
		else{
			e = query(max(e, 0), l-1);
			d = query(l-1, min(d, n-1));
			cout << max(e, d)-D[l] << endl;
		}
	}

	exit(0);
}
