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
	int n; cin >> n;
	map<int, int> mp;
	int ptr = 0;
	vector<int> v(n);
	for(auto &i: v) cin >> i;
	vector<int> w;
	w = v;
	sort(w.begin(), w.end());
	for(auto i : w) if(!mp.count(i)) mp[i] = ptr++;

	int at = 0;
	vector<ii> chain;
	for(int i=0;i <n; i++){	
		if(v[i] != v[at]){
			if(mp[v[i]] == mp[v[at]]+1)
			at = i;
		}
	}
	
	
	
	exit(0);
}
