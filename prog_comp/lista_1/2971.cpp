#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	int n, k; cin >> n >> k; k--;
	vector<vector<int>> v(n);
	string ord = "A23456789DQJK";
	map<char, int> mp;
	for(int i=1;i <=ord.size(); i++) mp[ord[i]] = i;
	for(int i=0;i <n; i++){
		string s; cin >> s;
		for(auto c : s){
			v[i].pb(mp[c]);
		}
	}
	v[k].pb(-1);
	int ans = 0, card=100;
	bool show = false;
	for(int i=0;i <n; i++){ if(i==k) continue;
		int cat = v[i][0];
		bool winner = true;
		for(auto x :v[i]) if(x!=cat) winner = false;
		if(winner and cat < card) show = true, ans = i, card = cat; 
	}
	if(show) return cout << ans+1 << endl, 0;

	bool has = false;
	int has_cor = k;
	while(true){
		vector<int> nv;
		int pass = -2;
		vector<int> cards(20);
		for(auto c : v[k]){ 
			if(c==-1 and has) pass = -1, has = false, has_cor = (k+1)%n;
			else if(c==-1) has = true, has_cor = k;
			else cards[c]++;
		}
		int maxi = 0, mini = 100; 
		for(auto x : cards) if(x) mini = min(mini, x), maxi = max(maxi, x);
		if(maxi == 4 and has_cor!=k){ans = k; break;} 
		if(pass==-2) for(int i=0; i<20; i++) if(cards[i]==mini) {pass = i; break;}
		for(int i=0;i <20; i++) for(int j=0; j<cards[i]-(pass==i); j++) nv.pb(i);
		if(has_cor==k) nv.pb(-1);
		v[k] = nv;
		k = (k+1)%n;
		v[k].pb(pass);
	}
	cout << ans+1 << endl;

	exit(0);
}
