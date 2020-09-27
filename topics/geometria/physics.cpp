#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
const ld pi = acos(-1);
ld eps = 1e-6;

ld r, h, v, g;
ld q(ld ang){
	ld a = g/2.0;
	ld b = -v*sin(ang);
	ld c = -h;
	ld t = (-b + sqrt(b*b - 4.0*a*c))/(2.0*a);
	ld dis = v*cos(ang)*t;
	return dis;
}

ld tern(ld l, ld r){
	if(abs(l-r)<eps) return l;
	ld m = (r-l)/3.0;
	ld q1 = q(l+m); ld q2 = q(r-m);
	if(q1>q2) r-=m;
	else l+=m;
	return tern(l, r);
}

int main(){
	ld ang= pi/4.0;
	while(cin >> r >> h >> v >> g){
		ld dis = q(tern(eps, pi/2.0-eps));
		if(dis<r) cout << "N" <<endl;
		else cout << "Y" << endl;
	}

}
