#include <bits/stdc++.h>

using namespace std;

typedef double ld;
ld l, w;
ld area(ld x){
	return (l-2*x)*(w-2*x)*x;
}

ld tern(ld a, ld b){
	for(int i=0; i<1000; i++){
		ld m = (b-a)/3.0;
		
		ld mid1 = a+m;
		ld mid2 = a+2.0*m;
	
		ld y1 = area(a+m);
		ld y2 = area(a+2.0*m);
	
		if(y2>y1) a = a+m;
		else if(y2<y1) b = a+2.0*m;
	}
	return a;
}

int main(){
	while(cin >> l >> w){
		ld mini1 = 0;
		ld mini2 = ld(min(w, l))/ld(2.0);

		
		ld maxi = tern(0, mini2);
		cout << setprecision(3) << fixed;
		cout << maxi << " " << mini1<< " " << mini2 << endl;
	}
		
}
