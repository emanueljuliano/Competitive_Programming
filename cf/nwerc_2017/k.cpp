#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2*4096 + 10;
int n;
int a[MAX];

map<tuple<int, int, int>, double> memo;

int pgt(int k){
	int x = 0;
	while ((1 << x) < k) x++;
	return 1 << x;
}

int plt(int k){
	int x = 0;
	while ((1 << (x+1)) <= k) x++;
	return 1 << x;
}

double p(int l, int r, int x){
	if (l == r) return 1.0;
	auto id = tuple(l, r, x);
	auto it = memo.find(id);
	if (it != memo.end()) return it->second;

	int el = r-l+1;
	int pg = pgt(el), pl = plt(el);
	int dl = abs(el - pl), dg = abs(el - pg);

	int m;
	if (dl >= dg){
		m = l + pg/2 - 1;
	}
	else{
		m = r - pl/2;
	}

	double ans = 0;
	if (x <= m){
		for (int i = m+1; i <= r; i++){
			ans += p(l, m, x)*p(m+1, r, i)*(double(a[x])/(a[x] + a[i]));
		}
	}
	else{
		for (int i = l; i <= m; i++){
			ans += p(l, m, i)*p(m+1, r, x)*(double(a[x])/(a[x] + a[i]));
		}
	}
	memo[id] = ans;
	return ans;
}

int main() { _
	cin >> n;
	cin >> a[n-1];
	for (int i = 0; i < n-1; i++)
		cin >> a[i];
	sort(a, a+n-1, greater<int>());

	double ans = p(0, n-1, n-1);
	cout << fixed << setprecision(12) << ans << endl;

	exit(0);
}
