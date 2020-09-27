#include<bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define _ ios::sync_with_stdio(0);cin.tie(0);
#define endl "\n"

using namespace std;

typedef long long ll;

const int MAX = 1e5+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;

int main(){_

	int n;
	cin >> n;
	vector<pair<double ,int> > v(n, make_pair(0, 1));
	for(int i = n-1; i >= 0; i--){
		int x; cin >> x;
		v[i].f = x;
	}
	bool flag = true;
	vector<pair<double,int> > ans;
	while(flag){
		flag = false;
		ans.resize(0);
		for(int i = 0; i < v.size(); i++){
			double sum = v[i].f;
			int qnt = v[i].s;
			int j = i+1;
			double rs = v[i].f;
			while(j != v.size() and ((v[j].f-rs > eps) or abs(v[j].f-rs) <= eps)){
				flag = true;
				sum += v[j].f;
				qnt += v[j++].s;
				rs = sum;
			}
			ans.pb({rs, qnt});
			i = j-1;
		}
		v = ans;
	}
	cout << setprecision(9) << fixed;
	for(int i = ans.size()-1; i>=0; i--){
		for(int j = 0; j < ans[i].s; j++)
			cout << ans[i].f/ans[i].s << endl;
	}
}


