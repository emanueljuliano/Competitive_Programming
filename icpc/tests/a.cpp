#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")

void f(){
	int a, b; cin >> a >> b;
	int qt = 0;
	while (1) {
		qt++;
		if ((b+qt+a-1)/a <= qt) {
			cout << qt << endl;
			return;
		}
	}
}

int main() { _
	unsigned v[300];
	fill(v, v+300, 1);

	int x = 3e4;
	int y = 300;
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			for (int k = 0; k < y; k++)
				v[j] += v[k];

	f();

	exit(0);
}

