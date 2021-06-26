#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MAX = 8e5+100;
pair<int, int> seg[2 * MAX];
int n2;

void build() {
	for(int i=n2; i<2*n2; i++) seg[i] = {-1, i-n2};
	for (int i = n2 - 1; i; i--) {
		seg[i] = max(seg[2*i], seg[2*i+1]);
	}
}

pair<int, int> query(int a, int b) {
	pair<int, int> ret = {-1, 1};
	for(a += n2, b += n2; a <= b; ++a /= 2, --b /= 2) {
		if (a % 2 == 1) ret = max(seg[a], ret);
		if (b % 2 == 0) ret = max(ret, seg[b]);
	}
	return ret;
}

void update(int p, int x) {
	seg[p+n2] = {x, p};
	p+=n2;
	while (p /= 2) seg[p] = max(seg[2*p], seg[2*p+1]);
}


int main(){ _
	int n; cin >> n;
	n2 = 4*n+10;
	vector<pair<int, int>> v(n);
	vector<vector<pair<int, int>>> ev(4*n+10);
	for (int i=0; i<n; i++) {
		int l, r; cin >> l >> r;
		v[i] = {l, r};
		ev[l].push_back({0, i});
		ev[r+1].push_back({1, i});
	}

	vector<int> nxt(4*n+10, -1), maxR(4*n+10, -1);

	set<pair<int, int>> st;
	queue<int> q;
	for (int i=0;i <ev.size(); i++) {
		for (auto [flag, id] : ev[i]) {
			//cout << flag << " " << id << endl;
			if (flag==0) st.insert({v[id].second, id});
			else {
				st.erase({v[id].second, id});
				while (q.size() and v[id].first>q.front()) {
					nxt[q.front()] = id;
					q.pop();
				}
			}
		}
		if(st.size()) maxR[i] = st.rbegin()->first;
		q.push(i);
	}

	build();
	vector<int> dp(4*n+10, -1);
	for(int i=4*n; i>=0; i--){
		if(maxR[i]==-1) {}
		else if(nxt[i] == -1) update(i, 0), dp[i] = 0;
		else if(maxR[i] >= v[nxt[i]].second) {}
		else {
			auto [val, pos] = query(maxR[i]+1, v[nxt[i]].second);
			//cout << val << " " << pos << endl;
			if(val==-1) {}
			else update(i, pos), dp[i] = pos;
		}
		//cout << i << " " << dp[i] << " " << maxR[i] << " " << nxt[i]<< endl;
	}
	
	int x = -1;
	for(int i=0;i <4*n; i++) if(dp[i]!=-1){
		x = i; break;
	}
	bool show = true;
	for(int i=0;i <n; i++) if(v[i].second<x) show = false;

	if(!show) cout << -1 << endl;
	else{
		vector<int> ans;
		ans.push_back(x);
		while(dp[x] != 0) x = dp[x], ans.push_back(x);
		cout << ans.size() << endl;
		for(auto u : ans) cout << u << " ";
		cout << endl;
	}


	exit(0);
}
