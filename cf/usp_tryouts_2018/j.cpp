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
const ll LINF = 0x3f3f3f3f3f3f3f3f;

char solve(int n){
	for(int i=25;i+1; i--){
		if(n==(1<<i)) return 'a'+i;
		else if(n>(1<<i)) return solve(n-(1<<i));
	}
	return 'a';
}

int main(){ _
	int n; cin >> n;
	cout << solve(n) << endl;
	
	exit(0);
}
