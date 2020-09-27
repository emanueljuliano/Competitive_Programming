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
	int n, m, k; cin >> n>> m >> k;
	
	for(int i=0; i<2*k; i++){
		int a, b; cin >> a >> b;	
	}
	cout << n-1+m-1+n*(m-1) + n-1 << endl;
	for(int i=0; i<n-1; i++) cout << 'U';
	for(int i=0; i<m-1; i++) cout << 'R';
	char at = 'R';
	for(int i=0; i<n; i++){
		if(at=='R') at = 'L';
		else at = 'R';
		for(int i=0; i<m-1; i++) cout << at;
		if(i!=n-1)cout << 'D';
	}
	cout << endl;
	
	
	exit(0);
}
