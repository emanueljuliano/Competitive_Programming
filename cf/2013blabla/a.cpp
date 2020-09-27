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
 
int log2(int x){
	int e = 0;
	int b = 1;
	while (2*b <= x){
		e++;
		b *= 2;
	}
	return e;
}
 
int main(){ _
	int n, k;
	cin >> n >> k;
	if (k == 1)
		return cout << n-1 << endl, 0;
	if(n==k)
		return cout << -1 << endl, 0;
	if(n-k >= k/2){
		int x = n/k;
		int ans = max(x - 1 + log2(k), x + log2(n%k));
		cout << ans << endl;
 		exit(0);
	}
	int x = k/(n-k);
	int ans = x + log2(n-k);
	cout << ans << endl;

	exit(0);
}
