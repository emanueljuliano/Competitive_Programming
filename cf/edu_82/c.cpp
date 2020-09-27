#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;

vector<vector<int>> v(27);
int visto[27];

void dfs2(int x){
	visto[x] = 1;
	for(int i=0; i<v[x].size(); i++){
		int w= v[x][i];
		if(!visto[w])
			dfs2(w);
	}
}

void dfs(int x){
	visto[x] = 1;
	cout << (char)('a'+x);
	for(int i=0; i<v[x].size(); i++){
		int w= v[x][i];
		if(!visto[w])
			dfs(w);
	}
}

int main(){ _
	int t; cin >> t;
	map<int, set<int> > me;
	while(t--){
		memset(visto, 0, sizeof(visto));
		for(int i=0; i<26; i++) v[i].resize(0);
		me.clear();

		string s; cin >> s;
		for(int i=0; i<s.size()-1; i++){
			int c = s[i]-'a';
			int b = s[i+1]-'a';
			if(!me[b].count(c)){
				v[b].pb(c);
				me[b].insert(c);
			}
			if(!me[c].count(b)){
				v[c].pb(b);
				me[c].insert(b);
			}
		}
		int indum = 0;
		int um = 0;
		bool mais = false;
		int dois = 0;
		for(int i=0; i<26; i++){
//			cout << char(i+'a') << " " <<v[i].size() << endl;
			if(v[i].size()==1) um++, indum=i;
			else if(v[i].size()>2) mais = true;
			else if(v[i].size()==2) dois++;
		}
		if(mais){
			cout << "NO" << endl;
			continue;
		}
		if(um==0 and dois==0){
			cout << "YES" << endl;
			for(int i=0; i<26; i++){
				cout << char(i+'a');
			}
			cout << endl;
			continue;
		}
		if(mais or um!=2){
			cout << "NO" << endl;
			continue;
		}
		else{
			dfs2(indum);
			bool flag = false;
			for(int i=0; i<26; i++){
				if(v[i].size()!=0 and !visto[i]){
					cout << "NO" << endl;
					flag = true;
				}
			}
			if(flag) continue;
			for(int i=0; i<26; i++) visto[i] = 0;

			cout << "YES" << endl;
			for(int i=0; i<26; i++){
				if(v[i].size()==0){
					cout << (char)('a'+i);
				}
				else if(v[i].size()==1 and !visto[i]){
					dfs(i);
				}
			}
			cout << endl;
		}
	}


	exit(0);
}
