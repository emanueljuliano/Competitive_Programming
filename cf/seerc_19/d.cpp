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
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	string s; cin >> s;
	sort(s.begin(), s.end());
	int n = s.size()/2;
	vector<int> f(26);
	for(auto u : s) f[u-'a']++;
	int c = -1;
	for(int i=0;i <26; i++) if(f[i]>n) c = i;
	if(c==-1){
		cout << "YES" << endl;
		cout << s << endl;
		exit(0);
	}

	vector<int> val;
	for(int i=0;i <26; i++) if(i!=c and f[i]>0) val.pb(i);
	if(val.size()>=2){
		cout << "YES" << endl;
		for(int i=0; i<n; i++) cout << char('a'+c);
		cout << char(val[0]+'a');
		f[c]-=n, f[val[0]]--;
		for(int i=0;i <f[c]; i++) cout << char('a'+c);
		f[c] = 0;
		for(int i=0;i <26; i++) for(int j=0; j<f[i]; j++) cout << char('a'+i);
		cout << endl;
	}
	else if(!val.size()) cout << "NO" << endl;
	else{
		if(f[val[0]]<=2) cout << "NO" << endl;
		else{
			cout << "YES" << endl;
			for(int i=0;i <n; i++) cout << char('a'+c);
			for(int i=1; i<f[val[0]]; i++) cout << char('a'+val[0]);
			f[c]-=n;
			for(int i=0; i<f[c]; i++) cout << char('a'+c);
			cout << char('a'+val[0]);
			cout << endl;
		}
	}

	
	exit(0);
}
