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
	int n, c, b; cin >> n>> c >> b;
	vector<int> val(n, 1);
	vector<int> ans(n);
	for(int i=0;i <b; i++){
		int a; cin >> a; a--;
		val[a] = 0;
	}

	bool flag = false;
	if(c%2) ans[0] = 1, c--, flag=true;
	for(int i=1+flag;i <n and c; i++){
		if(val[i]) c-=2, ans[i]=1, i++;
	}
	for(auto u : ans) cout << u;
	cout << endl;
	
	
	
	exit(0);
}
