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

int rand(int a, int b){
	return rand()%(b-a+1) + a;
}

int main(int argc, char** argv){ _
	srand(atoi(argv[1]));
	
	vector<int> v(3);
	int n = 10;
	v[0] = rand(1, n);
	v[1] = rand(1, n);
	v[2] = rand(1, n);
	sort(v.begin(), v.end());
	int l = v[0], k = v[1], r = v[2];
	int t = rand(1, n), x = rand(1, n), y = rand(1, n);
	cout << k << " "  << l << " " << r <<  " " << t << " " << x << " " << y << endl;

	exit(0);
}
