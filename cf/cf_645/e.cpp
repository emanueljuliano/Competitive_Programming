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
const int MAX = 5e5+10;

int seg[2 * MAX];
int n;

void build() {
	for (int i = n - 1; i; i--) seg[i] = seg[2*i] + seg[2*i+1];
}

int query(int a, int b) {
	int ret = 0;
	for(a += n, b += n; a <= b; ++a /= 2, --b /= 2) {
		if (a % 2 == 1) ret += seg[a];
		if (b % 2 == 0) ret += seg[b];
	}
	return ret;
}

int main(){ _
	cin >> n;
	for(int i=0;i <(n+1)/2; i++) cin >> seg[n+i];
	int x; cin >> x;
	for(int i=(n+1)/2; i<n; i++) seg[n+i]=x;
	build();
	bool val = false;
	int ans = 0;
	int id1=0, id2=0;
	while(ans<n and id1+ans<n){
		if(query(id1, id1+ans-1) >0){
			id1++;
		}
		else{
			if(id1>0) id1--, ans++;
			else ans++;
		}
	}	
	bool show = true;
	for(int i=0;i <=n-ans; i++){
		if(query(i, i+ans-1)<=0) show = false;
	}
	if(show) cout << ans << endl;
	else cout << -1 << endl;


	exit(0);
}
