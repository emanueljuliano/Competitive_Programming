#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	int n; cin >> n;

	vector<tuple<int, int, int, int>> v(n);
	for(auto &[a, b, c, d] : v) cin >> a >> b >> c >> d;

	double l = 0, r = 1e9+1;

	for(int i=0;i <60; i++){
		double m = (l+r)/2;
		double at = 0;
		for(auto [a, b, c, d] : v){
			// ganha m por segundo
			// ganha a*m por a segundos
			// esta ganhando b-a*m usando o primeiro
			double x1 = b-a*m, x2 = d-c*m;
			at += max(x1, x2);
		}
		if(at<0) r = m;
		else l = m;
	}

	cout << setprecision(10) << fixed;
	cout << (l+r)/2 << endl;
	
	
	
	exit(0);
}
