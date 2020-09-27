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
vector<int> v;
int n, m;
bool val(int x){
	int at = 0;
	for(int i=0;i <v.size(); i++){
		if(v[i]>at and x){
			x--;
			at++;
		}
		else if(v[i]<=at){
			at++;
		}
	}
	return at>=m;
}

int bb(int l, int r){
	if(l>=r) return l;
	int m = (l+r)/2;
	if(val(m)){
		r = m;	
	}
	else{
		l = m+1;
	}
	return bb(l, r);
}

int main(){ _
	cin >> n >> m;
	for(int i=0; i<n; i++){
		int a; cin >> a; v.pb(a);
	}
	
	int ans = bb(0, n);

	cout << ans << endl;
	
	exit(0);
}
