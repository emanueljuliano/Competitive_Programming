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
	string s; cin>>s;
	string x;
	for(int i=0; i<(s.size())/2; i++){
		x.pb(s[i]);
	}
	if(s.size()%2) x.pb(s[s.size()/2]);
	for(int i=(s.size())/2-1; i>=0; i--){
		x.pb(s[i]);
	}
	cout << x << endl;
	
	
	
	exit(0);
}
