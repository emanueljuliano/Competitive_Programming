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

const int LIM = 10;

int main(int argc, char** argv) { _
	srand(atoi(argv[1]));
	int n = rand()%LIM+1;
	cout << n << endl;
	vector<int> p(n);
	iota(p.begin(), p.end(), 0);
	function<int(int)> find = [&](int i) { return p[i] == i ? p[i] : p[i] = find(p[i]); };
	for (int i = 0; i < n-1; i++) {
		while (1) {
			int a = rand()%n, b = rand()%n;
			if (find(a) == find(b)) continue;
			cout << a+1 << " " << b+1 << endl;
			break;
		}
	}
	exit(0);
}
