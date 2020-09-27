#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


const int MAX = 1e6+10;
int seg[2 * MAX];
int n=MAX-2;

void build() {
	for (int i = n - 1; i; i--) seg[i] = seg[2*i] + seg[2*i+1];
}

int query(int a, int b) {
	int ret = 0;
	for(a += n, b += n; a <= b; ++a /= 2, --b /= 2) {
		if (a % 2 == 1) ret += seg[a];
		if (b % 2 == 0) ret += seg[b];
	}
	return ret;
}

void update(int p, int x) {
	seg[p += n] += x;
	while (p /= 2) seg[p] = seg[2*p] + seg[2*p+1];
}

int main(){ _
	int x, m; cin >> x >> m;
	for(int i=0;i <x; i++){
		int a; cin >> a;
		seg[n+a]++;
	}
	build();
	for(int i=0;i <m; i++){
		int k; cin >> k;
		if(k<0){
			k = -k;
			int l = 0; int r =n;
			while(l<r){
				int mid = (l+r)/2;
				int q = query(l, mid);
				if(q>=k) r = mid;
				else l = mid+1, k-=q;
			}
			//cout << "q = " << l << endl;
			update(l, -1);
		}
		else{
			update(k, 1);
		}
	}
	if(query(0, n)==0) cout << 0 << endl;
	else{
		int k = 1;
		int l = 0; int r = n;
		while(l<r){
			int mid = (l+r)/2;
			int q = query(l, mid);
			if(q>=k) r = mid;
			else l = mid+1, k-=q;
		}
		cout << l << endl;
	}
}
