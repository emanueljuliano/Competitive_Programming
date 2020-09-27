#include <bits/stdc++.h>

using namespace std;

#define pb push_back

typedef long long ll;
const int MAX = 202345;
int t[4*MAX];
int a[MAX];

void build(int i, int l, int r){
	if(l==r) t[i] = a[l];
	else{
		int m = (l+r)/2;
		build(2*i, l, m);
		build(2*i+1, m+1, r);
		t[i] = t[2*i] + t[2*i+1];
	}
}

int query(int i, int l, int r, int ql, int qr){
	if(ql<=l && r<=qr) return t[i];
	if(qr<l || r<ql) return 0;
	int m = (l+r)/2;
	int p1= query(2*i, l, m, ql, qr);
	int p2 = query(2*i+1, m+1, r, ql, qr);
//	cout << i << " l " << l << " r " << r  << " p1 "<< p1 << " p2 " << p2 << endl;
	return p1 + p2;
}

void update(int i, int l, int r, int p, int x){
	if(l==r) t[i]=x;
	else{
		int m = (l+r)/2;
		if(p<=m) update(2*i, l, m, p, x);
		else update(2*i+1, m+1, r, p, x);
		t[i] = t[2*i] + t[2*i+1];
	}
}

int main(){ ios_base::sync_with_stdio(0);cin.tie(0);
	int count=1;
	while(true){
		int n;
		cin >> n;
		if(n==0) exit(0);
		for(int i=1; i<=n; i++){
			cin >> a[i];
		}
		build(1, 1, n);
		if(count !=1) cout << endl;
		cout << "Case " << count << ":"<<endl; 
		while(true){
			string s;
			int x, y;
			cin >> s;
			if (s=="END") break;
			cin >> x >> y;
			if (s[0]=='M'){
				cout << query(1, 1, n, x, y) << endl;
			//	for(int i=1; i<=n; i++) cout << query(1, 1, n, i, i) << " ";
			//	cout << endl;
			}
			else
				update(1, 1, n, x, y);
		}
		//cout << endl;
		count++;
	}
	exit(0);
}
