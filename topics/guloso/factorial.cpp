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

	vector<int> fat(11);
	fat[0] = 1;
	for(int i=1; i<=10; i++) fat[i] = fat[i-1]*i;

	int ans =0;
	for(int i=10; i>0; i--){
		int at = n/fat[i];
		ans += at;
		n -= at*fat[i];
	}

	cout << ans << endl;
	
	
	
	exit(0);
}
