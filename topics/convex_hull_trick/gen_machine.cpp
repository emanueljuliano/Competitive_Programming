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

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r){
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

int main(int argc, char**argv){ _
	srand(atoi(argv[1]));
	
	int mx = 10;
	int n=uniform(1, mx/2), c = uniform(1, mx), d = uniform(1, 2*mx);
	cout << n << " " << c << " " << d << endl;
	for(int i=0;i <n; i++){
		int dd=uniform(1, mx), r=uniform(1, mx), p=uniform(1, mx), g=uniform(1, mx);
		dd%=d;
		cout << dd << " " << r << " " << p << " " << g << endl;
	}
	cout << "0 0 0" << endl;
	exit(0);
}
