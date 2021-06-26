#include<bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
const ld eps = 1e-8;

int main(){ _
	int n; cin >> n;
	vector<pair<int, int>> v(n);
	for(auto &[a, b] : v) {
		cin >> a >> b;
		if(a<b) swap(a, b);
	}
	pair<ld, ld> inter = {0, 1};
	
	for(int i=0;i <n-1; i++){
		int b1 = v[i].first, b2 = v[i+1].first;
		int a1 = v[i].second-v[i].first, a2 = v[i+1].second - v[i+1].first;

		if(a1==a2 and b1<b2) return cout << "NO" << endl, 0;
		else if(a1==a2) continue;
		else if(a1 > a2) {
			ld x = (b2-b1)/ld(a1-a2);
			if(inter.second+eps < x) return cout << "NO" << endl, 0;
 			else inter.first = max(inter.first, x);
		}
		else{
			ld x = (b2-b1)/ld(a1-a2);
			if(inter.first > x+eps) return cout << "NO" << endl, 0;
 			else inter.second = min(inter.second, x);
		}

		ld y1 = (1-inter.first)*v[i].first + inter.first*v[i].second;
		ld y2 = (1-inter.first)*v[i+1].first + inter.first*v[i+1].second;
		assert(y1+eps >= y2);
	}
	cout << "YES" << endl;

}
