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
	
	map<char, int> mp;
	vector<char> back(100);
	int ptr = 0;
	vector<int> v(100);

	for(auto u : s){
		if(!mp.count(u)) mp[u]=ptr++;
		v[mp[u]]++;
		back[mp[u]] = u;
	}
	
	vector<int> div;
	for(int i=1; i<=n; i++) if(n%i==0){
		div.pb(i);
	}
	
	int imp = 0;
	for(auto u : v) imp += u%2;
	int ans = 0;
	for(auto d : div){
		int sz = n/d;
		if(sz%2 and d%2!=imp%2) continue;
		if(sz%2 and imp>d) continue;
		if(sz%2==0 and imp) continue; 
		ans = d;
		break;
	}

	int sz = n/ans;
	cout << ans << endl;
	for(int t=0;t <ans; t++){
		string at;
		int tot = sz/2;
		while(tot) {
			for(int i=0; i<ptr and tot; i++){
				if(v[i]>=2) v[i]-=2, at+=back[i], tot--;
			}
		}
		string aux; aux = at;
		reverse(aux.begin(), aux.end());
		if(sz%2){
			if(imp){
				for(int i=0;i <ptr; i++) if(v[i]%2){at+=back[i], v[i]--, imp--; break;}
			}
			else{
				for(int i=0;i <ptr; i++) if(v[i]){at+=back[i], v[i]--; break;}
			}
		}
		at += aux;
		cout << at << " ";
	}
	cout << endl;
	
	
	exit(0);
}
