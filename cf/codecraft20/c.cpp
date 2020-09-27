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
	int n, m, p; cin >> n >> m >> p;
	vector<int> v, w;
	int ans1=-1, ans2=-1;
	
	for(int i=0;i <n; i++){
		int a; cin >> a; v.pb(a);
		if(a%p!=0 and ans1==-1) ans1 = i;
	}
	
	for(int i=0;i <m; i++){
		int a; cin >> a; w.pb(a);
		if(a%p!=0 and ans2==-1) ans2 = i;
	}
	cout << ans1+ans2 << endl;


	exit(0);
}
