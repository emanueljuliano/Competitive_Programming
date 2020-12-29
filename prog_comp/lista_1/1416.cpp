#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> ii;

int main(){ _
	int t, p;
	while(true){
		cin >> t >> p; if(!t) break;
		vector<vector<ii>> v;
		for(int i=0;i <t; i++){
			vector<ii> w;
			for(int j=0; j<p; j++){
				string s; cin >> s;
				int divi = 0;
				while(s[divi]!='/') divi++;
				
				int p10 = 1, fa=0, tp=0;
				for(int k=divi-1; k+1; k--) fa += p10*(s[k]-'0'), p10*=10;
				
				p10 = 1; 
				for(int k=s.size()-1; k>divi; k--) tp += p10*(s[k]-'0'), p10*=10;
				
				if(s[divi+1]=='-') tp = -1;
				w.pb({fa, tp});
			}
			v.pb(w);
		}
		
		auto val = [&](int x){
			vector<vector<int>> ret(t);
			map<int, map<ll, vector<int>>> mp; // quest / pont / coloc
			for(int i=0; i<t; i++){
				ll pt = 0; int qs = 0;
				for(auto pa : v[i]) if(pa.s!=-1) pt += pa.s+(ll)pa.f*x, qs--;
				mp[qs][pt].pb(i);
			}
			int ptr = 0;
			for(auto quest : mp) for(auto pont : quest.s){
				for(auto i : pont.s) ret[ptr].pb(i);
				ptr++;
			}
			return ret;
		};
		auto col = val(20);
		
		ii ans;
		int l=1, r = 20;
		while(l<r){
			int m = (l+r)/2;
			if(val(m)==col) r = m;
			else l = m+1;
		}
		ans.f = l;
		l = 20, r = 1e9;
		while(l<r){
			int m = (l+r+1)/2;
			if(val(m)==col) l = m;
			else r = m-1;
		}
		ans.s = l;
		if(ans.s==1e9) cout << ans.f << " *" << endl;
		else cout << ans.f << " " << ans.s << endl;
	}


	exit(0);
}
