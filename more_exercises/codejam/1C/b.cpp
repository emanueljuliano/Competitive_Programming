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
	int t; cin >> t; int cs = 0;
	while(t--){ cs++; cout << "Case #" << cs << ": ";
		vector<int> v(27);
		for(int i=0; i<27; i++) v[i] = 100;
		int u; cin >> u;
		vector<pair<int, string>> ev;
		for(int i=0;i <(int)1e4; i++){
			int q; string s; cin >> q >> s;
			if(q<10){
				int a = s[0]-'A'; int b;
				if(s.size()>1) b = s[1]-'A';
				if(s.size()>1) v[a] = 0, v[b] = min(v[b], q);
				else v[a] = min(v[a], q);
			}
			else{
				int a = s[0]-'A'; int b;
				if(s.size()>1) b = s[1]-'A';
				if(s.size()>1){ev.pb({q,s});}
				else v[a] = min(v[a], q);
			}
		}
		set<int> st;
		for(int i=0;i <100; i++){
			bool poe = true;
			for(int j=0; j<26; j++) if(v[j]==i) poe=false;
			if(poe) st.insert(i);
		}
		for(int i=0;i <26; i++) cout << v[i] << " ";
		cout << endl;
		sort(ev.begin(), ev.end());
		for(auto IT : ev){
			int q = IT.f; string s = IT.s;
			int a = s[0]-'A';
			int b = s[1]-'A';
			if(!st.count(0)){
				if(v[a]==0){
					v[b] = q;
					if(st.count(q));st.erase(q);
				}
				else{
					v[a] = q/10;
					v[b] = q%10;
					if(st.count(v[a])) st.erase(v[a]);
					if(st.count(v[b])) st.erase(v[b]);
				}
			}
			else{
				if(v[a] < 10){
				//	cout << q << " "<< s << endl;
				}
				if(v[a] < q/10){
				//	cout << a << " " << v[a] << " " << q << endl;
					v[a] = 0;
				}
				else if(v[b] < q){
				//	v[a] =min(v[a],  q/10);
				//	v[b] = min(v[b], q%10);
					if(st.count(v[a])) st.erase(v[a]);
					if(st.count(v[b])) st.erase(v[b]);
				}
				else{
					v[b] = min(v[b], q);
				}
			}
		}
		for(int i=0;i <26; i++) cout << v[i] << " ";
		cout << endl;
		vector<int> ans(100, -1);
		for(int i=0;i <26; i++) ans[v[i]] = i;
		for(int i=0;i <10; i++) cout << char(ans[i]+'A');
		cout << endl;
	}
		
	exit(0);
}
