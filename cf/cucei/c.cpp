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
	string s;
	vector<string> v;
	for(int i=0;i <n; i++){
		string t; cin >> t;
		s+=t;
		v.pb(t);
	}

	int k; cin >> k; k--;
	int a = s.size();
	int cic = (k/a)%n;
	int res = k%s.size();
	vector<string> w;
	s.clear();	
	for(int i=cic; i<v.size(); i++) s+=v[i];
	for(int i=0; i<cic; i++) s+=v[i];
	

	cout << s[res] << endl;
	
	
	
	exit(0);
}
