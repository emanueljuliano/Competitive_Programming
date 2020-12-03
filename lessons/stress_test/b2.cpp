#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


int main(){ _
	int n; cin >> n;
	int sum = 0;
	vector<ii> v(n);
	for(auto &[a, b] : v) cin >> a >> b, sum+=a;
	vector<ii> w = v;
	for(int i=1; i<=sum; i++){
		while(true){
			bool show = true;
			int at = i;
			for(auto [a, b] : v){
				if(at<a) show = false;
				at -= b;
			}
			if(show) return cout << i << endl, 0;
			if(!next_permutation(v.begin(), v.end())) break;
		}
	}
	exit(0);
}
