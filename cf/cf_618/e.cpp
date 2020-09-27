#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


const int N = 1000345;

double a[N];

struct no{
	double s = 0;
	double s2 = 0;
	double min = 0;
	int minp = 0;
	int sz = 0;
};

no t[4*N];

void build(int i, int l, int r) {
	if (l == r) {
		t[i].s = a[l];
		t[i].s2 = a[l];
		t[i].min = a[l];
		t[i].sz = 1;
		t[i].minp = 1;
	} else {
		int m = (l+r)/2;
		build(2*i, l, m);
		build(2*i+1, m+1, r);

		t[i].s = t[2*i].s + t[2*i+1].s;
		t[i].sz = t[2*i].sz + t[2*i+1].sz;
		cout << i << endl;
		cout << "l " << l << " r " << m<< " " << t[2*i].min << endl;
		cout << "l " << m+1 << " r " << r << " " << t[2*i+1].min << endl;		

		double media = (t[2*i].s + t[2*i+1].s2)/(double)(t[2*i].sz + t[2*i+1].minp);
		if(t[2*i].min<media){
			t[i].minp = t[2*i].minp;
			t[i].min = t[2*i].min;
			t[i].s2 = t[2*i].s2;
		}
		else{
			t[i].min = media;
			t[i].minp = t[2*i].sz + t[2*i+1].minp;
			t[i].s2 = t[2*i].s + t[2*i+1].s2;
		}
	}
}

no query(int i, int l, int r, int ql, int qr) {
	if (ql <= l && r <= qr) return t[i];
	if (qr < l || r < ql){
		no ret;
		ret.min = 1000000000000;
		ret.s =   0;
		ret.s2 =  0;
		ret.sz = 0;
		ret.minp = 0;
	//	cout << "UE" << endl;
		return ret;
	}
	int m = (l+r)/2;

	no q1 = query(2*i, l, m, ql, qr);
	no q2 = query(2*i+1, m+1, r, ql, qr);
	cout << q1.min << " " << q2.min << endl;
	no ret;
	ret.s = q1.s + q2.s;
	ret.sz = q1.sz +q2.sz;
	

	double media = (q1.s + q2.s2)/(double)(q1.sz + q2.minp);
	if(q1.min<media){
		ret.minp = q1.minp;
		ret.min = q1.min;
		ret.s2 = q1.s2;
	}
	else{
		ret.min = media;
		ret.minp = q1.sz + q2.minp;
		ret.s2 = q1.s + q2.s2;
	}
	
	return ret;
}

int main(){ _
	int n; cin >> n;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	build(1, 1, n);
	for(int i=1; i<n; i++){
		cout << i << "--------------" << endl;
		no at = query(1, 1, n, i, n);
	//	cout << at.min << endl;
		if(at.min<a[i]){
			for(int j=0; j<at.minp; j++){
				a[i+j] = at.min;
			}
			i+=at.minp-1;
		}
	}
	cout << setprecision(9) << fixed;
	for(int i=1; i<=n; i++){
		cout << a[i] << endl;
	}
	exit(0);
}
