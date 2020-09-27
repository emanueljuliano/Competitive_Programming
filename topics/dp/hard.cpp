#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<string> s;
vector<ll> v;

bool menor(int x, int p, int p2){
	if(!p2){
		if(!p){
			for(int i=0; i<s[x].size() and i<s[x+1].size(); i++){
				if(s[x][i] < s[x+1][i]) return true;
				if(s[x][i] > s[x+1][i]) return false;
			}
		}
		else{
			int aux2=s[x].size()-1;
			for(int i=0; i<s[x].size() and i<s[x+1].size(); i++){
				if(s[x][aux2-i] < s[x+1][i]) return true;
				if(s[x][aux2-i] > s[x+1][i]) return false;
			}
		}
	}
	else{
		int aux = s[x+1].size()-1;
		if(!p){
			for(int i=0; i<s[x].size() and i<s[x+1].size(); i++){
				if(s[x][i] < s[x+1][aux-i]) return true;
				if(s[x][i] > s[x+1][aux-i]) return false;
			}
		}
		else{
			int aux2 = s[x].size()-1;
			for(int i=0; i<s[x].size() and i<s[x+1].size(); i++){
				if(s[x][aux2-i] < s[x+1][aux-i]) return true;
				if(s[x][aux2-i] > s[x+1][aux-i]) return false;
			}
		}
	}
	if(s[x].size() > s[x+1].size()) return false;
	return true;
}

int n;
ll pd[100100][2];

ll rec(int x, int p){
	if(x==n-1 and p==0) return 0;
	if(x==n-1) return v[x];
	if(pd[x][p]!=-1) return pd[x][p];

	ll ret = LINF;
	if(menor(x, p, 0))
		ret = rec(x+1, 0);
//	cout << x << " " << p << " "<< ret << endl;	
	if(menor(x, p, 1))
		ret = min(ret, rec(x+1, 1));
//	cout << x << " " << p << " " << ret << endl;	


	if(ret!=LINF and p==1) ret+=v[x];
	return pd[x][p] = ret;
}


int main(){ _
	cin >> n;
	for(int i=0; i<=n; i++)pd[i][0] = pd[i][1] = -1;
	for(int i=0; i<n; i++){
		ll a; cin >> a; v.pb(a);
	}	
	for(int i=0; i<n; i++){
		string a; cin >> a; s.pb(a);
	}
	ll ans = min(rec(0, 0), rec(0, 1));
	if(ans == LINF) return cout << -1 << endl, 0;
	cout << ans << endl;

	exit(0);
}
