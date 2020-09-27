#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	int tc; cin >> tc;
	vector<vector<int>> v(27);
	while(tc--){
		string s, t;
		cin >> s;
		cin >> t;
		bool pode = true;
		for(int j=0; j<t.size(); j++){
			for(int i=0; i<s.size(); i++){
				int a = s[i]-'a';
				v[a].pb(i);
			}
			string aux;
			for(int i=0; i<j; i++)
				aux.pb(t[i]);
			int at = s.size();
			bool flag = true;
			for(int i=aux.size(); i>=0; i--){
				int  c = aux[i]-'a';
				int low = lower_bound(v[c].begin(), v[c].end(), at) - v[c].begin();
				if(low == v[c].size()){
					flag = false;
					break;
				}
				else{
					at = v[c][low];
					vector<int> as;
					for(int k=0; k<v[c].size();k++)if(v[c][k]!=at) as.pb(v[c][k]);
					v[c] = as;
				}
			}
			if(!flag) continue;
			 at = -1;
			if(flag){
				for(int i=j; i<t.size(); i++){
					int c = t[i]-'a';
					int upp = upper_bound(v[c].begin(), v[c].end(), at) - v[c].begin();
					if(upp==v[c].size()){
						flag = false;
						break;
					}
					else{
						at = v[c][upp];
					}
				}
			}
			if(flag){
				cout << "YES" << endl;
				pode = false;
				break;
			}
		}
		if(pode){
			cout << "NO" << endl;
		}

	}

	exit(0);
}
