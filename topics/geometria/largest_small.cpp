#include <bits/stdc++.h>

using namespace std;

typedef double ld;
ld l, w;
int main(){
	while(cin >> l >> w){
		ld mini1 = 0;
		ld mini2 = ld(min(w, l))/ld(2.0);

        ld a = 12.0;
        ld b = -4.0*(w+l);
        ld c = w*l;
        ld maxi = (-b-sqrt(b*b - 4.0*a*c))/(2*a);
		cout << setprecision(3) << fixed;
		cout << maxi << " " << mini1<< " " << mini2 << endl;
	}
		
}
