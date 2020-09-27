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

string s;

int solve(int l, int r, int maxi){
	int sum=0;
	int len = r;
	
	int ret = r+1-l;
	for(int i=(l+r)/2, j=(l+1+r)/2; i>=l and j<=r; i--, j++){
		sum += abs(s[j] - s[i]);
		if(sum>maxi) break;
		ret = j+1-i;
		cout << i << " " <<j << " s " << sum <<endl;
	}
	return ret;

}

int main(){ _
	int t; cin >> t;
	while(t--){
		cin >> s;
		int q; cin >> q;
		while(q--){
			int a, b, maxi; cin >> a >> b >> maxi;
			a--; b--;
			cout << solve(a, b, maxi) << endl;
		}
	}
	
	
	
	exit(0);
}
