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
	string s; cin >> s;
	int at = 2;
	ii cur = {0, 0};
	vector<ii> ans;
	bool show = true;
	for(int i=0; i<s.size(); i++){
		char c = s[i];
		if(c=='D'){
			bool add = true;
			ii poscur = {0, -INF};
			for(auto u : ans) if(u.f==cur.f and u.s<cur.s){
				add = false;
				if(u.s>poscur.s) poscur = u;
			}
			if(!add) {
				cur = poscur;
				if(i==s.size()-1) show = false;
			}
			else{
				cur.s = -(at*=2);
				ans.pb(cur);
			}
			cur.s++;
		}
		if(c=='U'){
			bool add = true;
			ii poscur = {0, INF};
			for(auto u : ans) if(u.f==cur.f and u.s>cur.s){
				add = false;
				if(u.s<poscur.s) poscur = u;
			}
			if(!add) {
				cur = poscur;
				if(i==s.size()-1) show = false;
			}
			else{
				cur.s = (at*=2);
				ans.pb(cur);
			}
			cur.s--;
		}
		if(c=='L'){
			bool add = true;
			ii poscur = {-INF, 0};
			for(auto u : ans) if(u.s==cur.s and u.f<cur.f){
				add = false;
				if(u.f>poscur.f) poscur = u;
			}
			if(!add) {
				cur = poscur;
				if(i==s.size()-1) show = false;
			}
			else{
				cur.f = -(at*=2);
				ans.pb(cur);
			}
			cur.f++;
		}
		if(c=='R'){
			bool add = true;
			ii poscur = {INF, 0};
			for(auto u : ans) if(u.s==cur.s and u.f>cur.f){
				add = false;
				if(u.f<poscur.f) poscur = u;
			}
			if(!add) {
				cur = poscur;
				if(i==s.size()-1) show = false;
			}
			else{
				cur.f = (at*=2);
				ans.pb(cur);
			}
			cur.f--;
		}
	}
	if(!show) cout << "impossible" << endl;
	else{
		ii b = ans.back();
		cout << -b.f << " " << -b.s << endl;
		ans.pop_back();
		cout << ans.size() << endl;
		for(auto u : ans) cout << u.f-b.f << " " << u.s-b.s << endl;
	}
	
	exit(0);
}
