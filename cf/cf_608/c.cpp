#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	int n, sx, sy;
	cin >> n >> sx >> sy;
	int x1=0, x0=0, y1=0, y0=0;		
	for(int i=0; i<n; i++){
		int a, b;
		cin >> a >> b;
		int x, y;
		x = a-sx;
		y = b-sy;
		if(x>0) x1++;
		if(x<0) x0++;
		if(y>0) y1++;
		if(y<0) y0++;
	}

	if(x1 == max(x1, max(x0, max(y1, y0)))){
		cout << x1 << endl;
		cout << sx+1 << " " << sy << endl;
	}
	else if(x0 == max(x1, max(x0, max(y1, y0)))){
		cout << x0 << endl;
		cout << sx-1 << " " << sy << endl;
	}
	else if(y1 == max(x1, max(x0, max(y1, y0)))){
		cout << y1 << endl;
		cout << sx << " " << sy+1 << endl;
	}
	else if(y0 == max(x1, max(x0, max(y1, y0)))){
		cout << y0 << endl;
		cout << sx << " " << sy-1 << endl;
	}
	
	exit(0);
}
