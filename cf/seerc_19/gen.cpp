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

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r){
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

int main(int argc, char**argv){ _
	srand(atoi(argv[1]));
	int k = 5, p = 10;
	int n=rand()%k+1, s1=rand()%k+1, s2 = rand()%k+1;
	cout << n << " " << s1 << " " << s2 << endl;
	for(int i=0;i <n; i++){
		int x = rand()%k+1, y = rand()%k+1, t = uniform(1, p), r = uniform(1, p);
		if(x<y) swap(x, y);
		if(t<r) swap(t, r);
		cout << x << " " << t << " " << y << " " << r << endl;
	}
	
	
	
	exit(0);
}
