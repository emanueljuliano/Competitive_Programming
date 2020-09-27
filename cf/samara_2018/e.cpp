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
	string s, t; cin >> s >> t;
	string s1, s2;
	bool f = false;
	bool imp = false;
	int id1=-1, id2=-1;
	for(int i=0;i <s.size(); i++){
		if(s[i]!=t[i]){
			id1 = i;
			break;
		}
	}
	for(int i=s.size()-1;i>=0; i--){
		if(s[i]!=t[i]){
			id2 = i;
			break;
		}
	}
	
	if(id1!=-1)for(int i=id1; i<=id2; i++){
		s1.pb(s[i]);
		s2.pb(t[i]);
	}
	reverse(s1.begin(), s1.end());
	if(imp or s1!=s2){
		cout << "NO" << endl;
	}
	else cout << "YES" << endl;
	
	
	exit(0);
}
