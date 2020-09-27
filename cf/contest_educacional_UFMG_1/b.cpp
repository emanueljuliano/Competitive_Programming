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

string m2(string k){
	int e1 = 0;
	string nk;
	for(int i=k.size()-1; i+1; i--){
		nk.pb(2*(k[i]-'0')%10 + e1 + '0');
		e1 = 2*(k[i]-'0')/10;
	}
	if(e1) nk.pb(e1+'0');

	reverse(nk.begin(), nk.end());
	return nk;
}

int main(){ _
	int t; cin >> t;
	while(t--){
		string k; int m; cin >> k >>  m;
		
		while(m--){
			int g5 = -1;
			for(int i=k.size()-1; i+1; i--){
				if(k[i]-'0' >= 5) {g5=i; break;}
			}			
			if(g5 ==-1) k = m2(k);
			else k = k.substr(0, g5) + m2(k.substr(g5, k.size()-g5));
		}
		cout << k << endl;
	}
	
	
	exit(0);
}
