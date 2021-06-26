#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r){
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

int main(int argc, char** argv) {
	srand(atoi(argv[1]));
	
	int z = 1;
	cout << z << endl;
	while(z--) {
		int n = uniform(1, 5);
		cout << n << endl;
		for(int i = 0; i < n; i++)
			cout << uniform(1, 19) << ' '; 
		cout << endl;
	}
}
