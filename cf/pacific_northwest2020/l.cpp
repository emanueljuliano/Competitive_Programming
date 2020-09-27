#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<int> v;
vector<string> resp;

bool val(vector<int> w){
	for(int k=0; k<v.size(); k++){
		int at =0;
		for(int i=0; i<=k; i++) {
			if(k-i>w.size()-1 or i>w.size()-1) continue;
			at = (at+w[i]*w[k-i])%10;
		}
		if(at!=v[k]) return false;
	}
	return true;
}

void solve(vector<int> w, int p){
	if(w.size()!=p) return;
	
	if(2*p-1>v.size()) return;
	if(2*p-1==v.size()){
		if(!val(w)) return;
		string s;
		for(int i=w.size()-1; i+1; i--) s.pb(w[i]+'0');
		resp.pb(s);
		return;
	}

	int at = v[p];
	int coef = 2*w[0]%10;
	for(int i=1; i<w.size(); i++){
		at = (at-(w[i]*w[w.size()-i])%10+10)%10;
	}

	for(int i=0; i<10; i++) if(coef*i%10==at) {
		vector<int> w1=w;
		w1.pb(i);
		solve(w1, p+1);
	}
}

int main(){ _
	string s; cin >> s;	
	for(int i=s.size()-1; i+1; i--) v.pb(s[i]-'0');

	for(int i=0; i<10; i++) if(i*i%10==v[0]) {
		vector<int> w; w.pb(i);
		solve(w, 1);
	}

	if(!resp.size()) return cout << -1 << endl, 0;
	//for(auto u : resp) cout << u << endl;

	sort(resp.begin(), resp.end());
	cout << resp[0] << endl;

	exit(0);
}
