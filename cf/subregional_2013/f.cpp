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
	vector<int> v(n);
	int tot = 0;
	for(auto &i:v) cin >> i, tot+=i;

	set<int> st;
	vector<int> soma(n+1);
	for(int i=0;i <n; i++){
		soma[i+1] = soma[i] + v[i];
		st.insert(soma[i]);
	}
	if(tot%3) return cout << 0 << endl, 0;
	int ans = 0;
	for(int i=0;soma[i] <=tot/3; i++){
		if(st.count(soma[i] + tot/3) and st.count(soma[i] + 2*tot/3)) ans++;
	}
	cout << ans << endl;
	
	
	exit(0);
}
