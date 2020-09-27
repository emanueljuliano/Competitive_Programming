#include <bits/stdc++.h>
using namespace std;

const int N = 112345;
int t[4*N][3];
int lz[4*N];

struct mao{
	int a0, a1, a2;
};

void build( int i, int l, int r) {
	if (l == r) {
		t[i][0] = 1;
		t[i][1] = 0;
		t[i][2] = 0;
		
	} else {
		int m = (l+r)/2;
		build(2*i, l, m);
		build(2*i+1, m+1, r);
		t[i][0] = t[2*i][0] + t[2*i+1][0];
		t[i][1] = 0;
		t[i][2] = 0;
	}
}

void push( int i, int l, int r) {
	if (lz[i]) {
		int a0, a1, a2;
		a0=t[i][0];
		a1=t[i][1];
		a2=t[i][2];

		if(lz[i]%3==1){
			t[i][0] = a2;
			t[i][1] = a0;
			t[i][2] = a1;
		}
		else if(lz[i]%3==2){
			t[i][0] = a1;
			t[i][1] = a2;
			t[i][2] = a0;	
		}
		if (l != r) {
			lz[2*i] += lz[i];
			lz[2*i+1] += lz[i];
		}
		lz[i] = 0;
	}
}

mao query( int i, int l, int r, int ql, int qr){
	push(i, l, r);
	mao ret; ret.a0=0, ret.a1=0, ret.a2=0;
	if (ql <= l && r <= qr){
	ret.a0=t[i][0];
	ret.a1=t[i][1];
	ret.a2=t[i][2];
	return ret;
	}
	if (qr < l || r < ql) return ret;

	int m = (l+r)/2;
	mao p1 = query(2*i, l, m, ql, qr);
	mao p2 = query(2*i+1, m+1, r, ql, qr);
	mao ans;
	ans.a0 =p1.a0+p2.a0;
	ans.a1=p1.a1+p2.a1;
	ans.a2=p1.a2+p2.a2;
	return ans;
}

void update( int i, int l, int r, int ql, int qr, int x) {
	push(i, l, r);
	if (qr < l || r < ql) return;
	if (ql <= l && r <= qr) {
		lz[i] += x;
		push(i, l, r);
	} else {
		int m = (l+r)/2;
		update(2*i, l, m, ql, qr, x);
		update(2*i+1, m+1, r, ql, qr, x);
		
		t[i][0] = t[2*i][0] + t[2*i+1][0];
		t[i][1] = t[2*i][1] + t[2*i+1][1];
		t[i][2] = t[2*i][2] + t[2*i+1][2];
	}
}

int main(){
	int n, m;
	while(scanf("%d %d", &n, &m)!=EOF){
	for(int i=0; i<=4*n; i++)lz[i]=0;
	
	build(1, 1, n);
	for(int i=0; i<m; i++){
		char c;
		int x, y;
		cin >> c >> x >> y;
		if(c=='C'){
			auto ans =  query(1, 1, n, x, y);
			cout << ans.a0 << " " << ans.a1 << " "<< ans.a2 << endl;
		}
		else{
			update(1, 1, n, x, y, 1);		
		}
	}
	cout << endl;
	}
	exit(0);
}
