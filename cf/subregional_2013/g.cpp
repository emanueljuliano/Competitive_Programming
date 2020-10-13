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

int M[330][330];
const int MAX = 330;
int id[MAX], sz[MAX];

int find(int p){
	if(p==id[p]) return p;
	return id[p] = find(id[p]);
}

void une(int p, int q){
	p = find(p), q=find(q);
	if(p==q) return;
	if(sz[p]>sz[q]) swap(p, q);
	id[p] = q;
	sz[q] += sz[p];
}

void build(){
	for(int i=0;i <MAX; i++) sz[i]=1, id[i]=i;
}

int main(){ _
	int l, c; cin >> l >> c;

	set<int> st, st2;
	for(int i=0; i<l*c; i++) st.insert(i);
	bool show = true;
	
	for(int i=0;i <l; i++) for(int j=0; j<c; j++){
		cin >> M[i][j], M[i][j]--;
		if(st2.count(M[i][j])) show = false;
		if(!st.count(M[i][j])) show = false;
		st2.insert(M[i][j]);
	}

	for(int j=0; j<c; j++) for(int i=1; i<l; i++){
		if(M[i][j]%c != M[0][j]%c) show = false;
	}
	for(int i=0; i<l; i++) for(int j=1; j<c; j++){
		if(M[i][j]/c != M[i][0]/c) show = false;
	}
	
	if(!show) return cout << "*" << endl, 0;

	int ans = 0;
	build();
	for(int i=0;i <l; i++) une((M[i][0])/c, i);
	vector<int> vis(l);
	for(int i=0;i <l; i++) if(!vis[find(i)]) ans+=sz[find(i)]-1, vis[find(i)]=1;

	build();
	for(int i=0;i <c; i++) une((M[0][i])%c, i);
	vector<int> vis2(c);
	for(int i=0;i <c; i++) if(!vis2[find(i)]) ans+=sz[find(i)]-1, vis2[find(i)]=1;

	cout << ans << endl;

	exit(0);
}
