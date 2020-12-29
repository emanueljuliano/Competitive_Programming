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
const double LINF = 1e18;

struct atl{
	ll h, ht, c, ct;
	int id;
};

bool interh(atl a1, atl a2, atl a3){
	// l1 = a1.ht*x + a1.h
	// x = (a2.h-a1.h)/(a1.ht-a2.ht)
	return (a2.h-a1.h)*(a1.ht-a3.ht) >= (a3.h-a1.h)*(a1.ht-a2.ht);
}
double valh(atl a1, atl a2){
	return (a2.h-a1.h)/double(a1.ht-a2.ht);
}

bool interc(atl a1, atl a2, atl a3){
	return (a2.c-a1.c)*(a1.ct-a3.ct) >= (a3.c-a1.c)*(a1.ct-a2.ct);
}
double valc(atl a1, atl a2){
	return (a2.c-a1.c)/double(a1.ct-a2.ct);
}


int main(){ _
	int n; cin >> n;

	vector<atl> v(n);
	for(int i=0;i <n; i++) cin >> v[i].h >> v[i].ht >> v[i].c >> v[i].ct, v[i].id=i;

	// H
	sort(v.begin(), v.end(), [](auto a, auto b){
		if(a.ht!=b.ht) return a.ht<b.ht;
		return a.h < b.h;
	});
	vector<atl> w(n);
	int l = 0, r=0;
	for(int i=0;i <n; i++){
		while(r-l>=2 and interh(w[r-2], w[r-1], v[i])) r--;
		w[r++] = v[i];
		while(r>l+1 and w[l].h <= w[l+1].h) l++;
	}
	vector<pair<double, double>> range(n, {0, -1});
	vector<int> vis(n);
	for(int i=l; i<r; i++){
	//	cout << w[i].h << " " << w[i].ht << endl;
		vis[w[i].id]++;
		if(i>l) range[w[i].id].f = valh(w[i-1], w[i]);
		if(i<r-1) range[w[i].id].s = valh(w[i], w[i+1]);
	}
	range[w[r-1].id].s = LINF;
	
	//for(int i=0;i <n; i++) cout << i << ") " << range[i].f << " " << range[i].s << endl;

	// C
	sort(v.begin(), v.end(), [](auto a, auto b){
		if(a.ct!=b.ct) return a.ct>b.ct;
		return a.c > b.c;
	});
	l = 0, r=0;
	for(int i=0;i <n; i++){
		while(r-l>=2 and interc(w[r-2], w[r-1], v[i])) r--;
		w[r++] = v[i];
		while(r>l+1 and w[l].c >= w[l+1].c) l++;
	}
	
	for(int i=l; i<r; i++){
	//	cout << w[i].c << " " << w[i].ct << endl;
		vis[w[i].id]++;
		if(i>l) range[w[i].id].f = max(range[w[i].id].f,  valc(w[i-1], w[i]));
		if(i<r-1) range[w[i].id].s = min(range[w[i].id].s, valc(w[i], w[i+1]));
	}
	range[w[r-1].id].s = min(range[w[r-1].id].s, LINF);
	
	//for(int i=0;i <n; i++) cout << i << ") " << range[i].f << " " << range[i].s << endl;
	
	int ans = 0;
	for(int i=0;i <n; i++) ans += (vis[i]==2 and range[i].f+1e-7<+range[i].s); 

	cout << ans << endl;
	exit(0);
}
