#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

ld area(ld a, ld b, ld c){
	ld p = (a+b+c)/2;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}

ld solve(vector<ld> v){
//	cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << endl;
	ld r = min(v[0]+v[1], v[2]+v[3]);
	ld l = 0.0;
	ld ret = 0.0;
	for(int i=0;i <1000; i++){
		ld t = (r-l)/3.0;
		ld q1 = area(v[0], v[1], l+t) + area(v[2], v[3], l+t);
		ld q2 = area(v[0], v[1], r-t) + area(v[2], v[3], r-t);
		ret = max(q1, ret);
		ret = max(q2, ret);
		if(q1>q2) r -= t;
		else l+=t;
	}
	return ret;
}

int main(){
	ld a, b, c, d; cin >> a >> b >> c >> d;
	vector<ld> sq1 = {a, b, c, d};
	vector<ld> sq2 = {a, c, d, b};
	vector<ld> sq3 = {a, d, b, c};
	
	ld ans = 0;
	ans = max(solve(sq1), ans);
	ans = max(solve(sq2), ans);
	ans = max(solve(sq3), ans);
	cout << setprecision(9) << fixed;
	cout << ans << endl;
}


