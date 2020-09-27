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
	vector<string> S =  {"Do", "Do#", "Re", "Re#", "Mi", "Fa", "Fa#", "Sol", "Sol#",
		"La", "La#", "Si"};
	map<string, int> mp;
	int ptr=0;
	for(auto c : S){
		mp[c] = ptr++;
	}
	vector<int> mov = {0, 2, 4, 5, 7, 9, 11, 12};

	int n; cin >> n;
	vector<int> v;
	for(int i=0;i <n; i++){
		string s; cin >> s;
		v.pb(mp[s]);
	}
	for(int i=0;i <n; i++) v.pb(v[i]);
	
	vector<int> pos;
	for(int i=0;i <12; i++){
		int mask = 0;
		for(auto u : mov)
			mask |= 1<<((i+u)%12);
		pos.pb(mask);
	}
	
	vector<int> has(1<<12);
	for(int i=0;i <(1<<12); i++) for(auto msk : pos){
		if((msk|i)==msk) has[i]=1;
	}

	vector<int> cnt(ptr);
	vector<int> nxt(2*n);
	int it = 0, msk=0;
	for(int i=0;i <v.size(); i++){
		msk |= (1<<v[i]);
		cnt[v[i]]++;
		while(!has[msk]){
			nxt[it] = i;
			cnt[v[it]]--;
			if(!cnt[v[it]]) msk ^= (1<<v[it]);
			it++;
		}
	}
	while(it<2*n) nxt[it]=2*n, it++;
	
	if(nxt[0]>=n) return cout <<1  << endl, 0;
	
	
	vector<int> to(n), jump(n);
	for(int i=n-1; i+1; i--){
		if(nxt[i]>=n) to[i] = i, jump[i] = 0;
		else to[i] = to[nxt[i]], jump[i] = jump[nxt[i]]+1;
	}

	int ans = INF;
	for(int i=0;i <=nxt[0]; i++){
		if(nxt[to[i]] >= i+n) ans = min(ans, jump[i]+1);
		else ans = min(ans, jump[i]+2);
	}
	cout << ans << endl;
	
	exit(0);
}
