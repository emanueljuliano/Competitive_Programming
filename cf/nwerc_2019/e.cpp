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

const double eps = 1e-5;

int main(){ _
	vector<int> v(4);
	for(auto &i : v){
		double a; cin >> a;
		i = (a+eps)*100;
	}
	sort(v.begin(), v.end());
	double a; cin >> a;
	int exp = (a+eps)*100;
	int tot = v[1]+v[2];
	int nec = exp*3-tot;
	if(nec<v[0]) cout << "impossible" << endl;
	else if(nec>=v[3]) cout << "infinite" << endl;
	else cout << nec/100 << "." << nec%100/10 << nec%10 << endl;
	
	
	exit(0);
}
