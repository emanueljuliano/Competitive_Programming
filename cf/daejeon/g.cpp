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


int main(){ _
	int n, m; cin >> n >> m;
	vector<int> v, w;
	for(int i=0;i <2*n+1; i++){
		int a; cin >> a; v.pb(a);
	}
	for(int i=0;i <2*m+1; i++){
		int a; cin >> a; w.pb(a);
	}

	int l=v[0], u=w[0];
	vector<pair<ii, int>> ev;
	for(int i=1; i<2*n+1; i+=2){
		ev.pb({{v[i], v[i+1]}, 1});
	}
	for(int i=1; i<2*m+1; i+=2){
		ev.pb({{w[i], w[i+1]}, 0});
	}
	sort(ev.begin(), ev.end());

	

	ll ans = 0, k = 0, a2 = 0;;
	int x1 = 0;
	bool open = false;
	for(auto IT : ev){
		int x = IT.f.f, y = IT.f.s;
		bool flag = IT.s;
	//	cout << x << " " << y << " " << flag << endl;
	//	cout << "Area " << x << " " << x1 << " " << u << " "  << l << endl;
		if(!flag){ // UP
			if(u<l and y>l) open = true;
			
			ll area = (ll)(x-x1)*(ll)(u-l);
			if(open) a2 += max(area, 0ll);

			if(u>l and y<l){
				if(open) ans += a2, k++;
				open = false;
				a2=0;
			}

			x1 = x;
			u = y;
		} 
		else{ // DOWN
			if(u<l and u>y) open = true;

			ll area = (ll)(x-x1)*(u-l);
			if(open) a2 += max(area, 0ll);

			if(u>l and y>u){
				if(open)k++, ans += a2;
				
				a2=0;
				open = false;
			}

			x1 = x;
			l = y;
		}
	//	cout << "ATUAL = " << k << " " << ans << endl;
	}

	cout << k << " " << ans << endl;
	
	
	exit(0);
}
