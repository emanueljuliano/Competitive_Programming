#include <bits/stdc++.h>

using namespace std;

const int MAX = 100010;

namespace sam{
	int cur, sz, len[2*MAX], link[2*MAX], acc[2*MAX];
	int nxt[2*MAX][26];

	void add(int c){
		int at = cur;
		len[sz] = len[cur]+1, cur = sz++;
		while(at != -1 and !nxt[at][c]) nxt[at][c] = cur, at = link[at];
		if(at == -1) { link[cur] = 0; return;}
		int q = nxt[at][c];
		if(len[q] == len[at]+1){ link[cur] = q; return; }
		int qq = sz++;
		len[qq] = len[at]+1, link[qq] = link[q];
		for(int i=0; i<26; i++) nxt[qq][i] = nxt[q][i];
		while(at != -1 and nxt[at][c] == q) nxt[at][c] = qq, at = link[at];
		link[cur] = link[q] = qq;
	}

	void build(string& s){
		len[0] = 0; link[0] = -1; sz++;
		for(auto i: s) add(i-'A');
		int at = cur;
		while (at) acc[at] = 1, at = link[at];
	}
};


int main(){
	using namespace sam;
	memset(nxt, 0, sizeof(nxt));
	for(int i=0; i<MAX; i++)
		len[i] = 0, link[i] = 0, acc[i] = 0;
	string s; cin >> s;
	int n; cin >> n;
	build(s);

	for(int i=0; i<n; i++){
		bool flag = true;
		string a;
		cin >> a;
		int atu = 0;
		int ans = 1;
		for(int j=0; j<a.size(); j++){
			if(nxt[atu][a[j]-'A'] != 0){
				atu = nxt[atu][a[j]-'A'];
			}
			else{
				if(atu ==0){ cout << -1 << endl; flag=false; break; }
				ans++;
				atu = 0;
			}
		}
		if(flag){
			if(ans>1) ans++;
			cout << ans << endl;
		}
	}

	exit(0);
}
