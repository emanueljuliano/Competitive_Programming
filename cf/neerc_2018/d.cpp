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


int main(){ _
	int n; cin >> n;
	string s; cin >> s;
	vector<int> pref;
	pref.pb(0);
	vector<int> pac;
	for(int i=0;i <n; i++){
		char u = s[i];
		int novo = pref.back();
		novo += u=='*';
		pref.pb(novo);
		if(u=='P') pac.pb(i);
	} 

	int maxi = 0;
	int ans = INF;
	if(pac.size()==1){
		int pos = pac[0];
		maxi = pref.back() - pref[pos];
		for(int i=n-1;i>pos; i--) if(s[i]=='*') {ans = i-pos; break;}
		
		if(pref[pos] == maxi) {
			for(int i=0;i<pos; i++) if(s[i]=='*') {ans = min(ans, pos-i); break;}	
		}
		else if(pref[pos] > maxi) {
			maxi = pref[pos];
			for(int i=0;i<pos; i++) if(s[i]=='*') {ans = pos-i; break;}	
		}
		return cout << maxi << " " << ans << endl, 0;
	}

	maxi = pref.back();
	
	auto val = [&](int m){
	//	cout << endl;
	//	cout << "TESTE " << m << endl;
		vector<pair<ii, int>> ev;
		for(int i=0;i <pac.size(); i++){
			ev.pb({{pac[i]-m, -1}, i});
			ev.pb({{pac[i]+m, 1}, i});
		}
		for(int i=0;i <n; i++) if(s[i]=='*') ev.pb({{i, 0}, 0});
		sort(ev.begin(), ev.end());
		int last = -1;
		set<int> st;
		for(auto IT : ev){
			int x = IT.f.f, flag = IT.f.s, i = IT.s;
	//		cout << x << " " << i << " " << flag << " " << last <<  endl;
	//		cout << "st "; for(auto u : st) cout <<u << " ";
	//		cout << endl;
			if(flag==0){
				if(x<=last) continue;
				if(!st.size()) return false;
				else if(st.size()==1){
					int a = *st.begin(); st.erase(a);
					if(pac[a] > x) last = pac[a];
					else last = pac[a]+m;
				}
				else{
					auto it = st.begin();
					int a = *it; it++;
					int b = *it;
					if(pac[a] < x) st.erase(a), last = pac[a]+m;
					else if(pref[pac[a]]==pref[pac[b]]) st.erase(a), last = pac[a];
					else st.erase(b), last = pac[b];
				}
			}
			else if(flag==-1) st.insert(i);
			else if(st.count(i)) st.erase(i);	
		}
		return true;
	};

	int l = 1, r = n;
	while(l<r){
		int m = (l+r)/2;
		if(val(m)) r = m;
		else l = m+1;
	}

	cout << maxi << " " << l << endl;
	
	exit(0);
}
