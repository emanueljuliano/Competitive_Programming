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
	string s; cin >> s;
	int a = 0, b= 0;
	vector<int> A, B, SA, SB;
	for(int i=0;i <n; i++){
		if(s[i]=='A') a++, A.pb(i);
		if(s[i]=='B') b++, B.pb(i);
		SA.pb(a);
		SB.pb(b);
	}
	ll ans = 0;
	for(int i=0; i<n; i++){
	//	cout << ans << endl;
		if(s[i]=='A'){
			int up = upper_bound(A.begin(), A.end(), i) - A.begin();
			if(up==A.size()) continue;
			if(SB[i]==SB[A[up]] and SB[A[up]]!=b) ans += n-A[up]-1;
			else ans += n-A[up];
		}
		if(s[i]=='B'){
			int up = upper_bound(B.begin(), B.end(), i) - B.begin();
			if(up==B.size()) continue;
			if(SA[i]==SA[B[up]] and SA[B[up]]!=a) ans += n-B[up]-1;
			else ans += n-B[up];
		}
	}
	cout << ans << endl;
	
	
	
	exit(0);
}
