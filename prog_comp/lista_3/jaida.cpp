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
	const int MAX = 1e7+10;
	vector<bool>pri(MAX, 1);
	for(int i=2; i<MAX; i++) if(pri[i]) for(int j=i+i; j<MAX; j+=i) pri[j] = 0;

	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<bool> aux = pri;
		for(int i=0;i <n; i++){
			int a; cin >> a;
			if(a>=MAX) continue;
			aux[a] = false;
		}
		int ans = 1;
		while(!aux[ans]) ans++;
		cout << ans-1 << endl;
	}
	
	exit(0);
}
