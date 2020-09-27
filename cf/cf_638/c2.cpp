#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define sz(a) int((a).size())
#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int t, n, k;
string str;

int main(){ _

	cin >> t;
	while(t--) {
		cin >> n >> k;
		cin >> str;
		sort(str.begin(),str.end());
		if(k == 1) cout << str << endl;
		else {
			bool flag = str[k-1] == str[0];
			if(!flag) cout << str[k-1];
			else {
				map<char,int> m;
				for(auto u : str) m[u]++;
				if(sz(m) == 1) {
					for(int i=0; i<(n+k-1)/k; i++) cout << str[0];
				}
				else {
					bool dvdequal = true;
					if(sz(m) != 2) dvdequal = false;
					if(m[str[0]] != k) dvdequal = false;
					for(auto u : m) if(u.s % k) dvdequal = false;
					if(dvdequal) {
						for(auto u : m) {
							for(int i=0; i < u.s/k; i++) cout << u.f;	
						}	
					}
					else {
						cout << str[0];
						for(int i=k; i<sz(str); i++) cout << str[i];
					}
				}
			}
			cout << endl;
		}
	}

	exit(0);
}
