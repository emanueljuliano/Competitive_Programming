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
	int t = 1e5;
	ll maxi = 1e18-2*t;
	cout << t << endl;
	for(int i=0;i <t; i++){
		if(i%2) cout << maxi+t << " ";
		else cout << -maxi+t << " ";
		if(i%4) cout << maxi+t << endl;
		else cout << -maxi+t << endl;
	}
	
	
	
	exit(0);
}
