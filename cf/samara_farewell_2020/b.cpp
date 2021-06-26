#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r){
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

int main(){ _
	int n; cin >> n;
	vector<tuple<int, int, int, int>> v(n);
	vector<int> choices(n);

	for(auto &[a, b, c, d] : v) cin >> a >> b >> c >> d;
	double ans = 0;
	ll num=0, den=0;
	for(int i=0;i <n; i++) {
		choices[i] = uniform(0, 1);
		if(choices[i]==0) num += get<1>(v[i]), den += get<0>(v[i]);
		else num += get<3>(v[i]), den += get<2>(v[i]);
	}
	for(int it=0;it<15; it++){
		ll num2=0, den2=0;
		int i =0;
		for(auto [a, b, c, d] : v){
			if(choices[i]==0){
				if(double(num-b+d)/(den-a+c) > double(num)/den)
					choices[i] = 1, num2+=d, den2+=c;
				else num2 += b, den2+=a;
			}
			else{
				if(double(num-d+b)/(den-c+a) > double(num)/den)
					choices[i] = 0, num2+=b, den2+=a;
				else num2+=d, den2+=c;
			}
			i++;
		}
		num = num2, den = den2;
		ans = max(ans, double(num)/den);
	}
	cout << setprecision(10) << fixed;
	cout << ans << endl;



	exit(0);
}
