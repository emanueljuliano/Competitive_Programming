#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"
#define pb push_back
#define ss second
#define ff first

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

bool eq(ld a, ld b){
	return abs(a -b) < 1e-9;
}

int main(){
	int n;
	cin >> n;

	vector<pair< pii, double>> v;
	map<pii, vector<double>> dist;
	for(int i=0; i<n; i++){
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		double d;
		int a = x1-x2;
		int b = y1-y2;
		pii ind;

		if(a==0)
			ind = {0, -1}, d = x1;
		
		else if(b==0)
			ind = {1, 0}, d = y1;
		
		else{
			int g = __gcd(a, b);
			ind = {a/g, b/g};
			if(ind.ff<0) ind = {-ind.ff, -ind.ss};
			d = y1-ld(ld(a)/b)*x1;

		}
		bool ig = false;
		for(int j=0; j<v.size(); j++){
			int xx = v[j].ff.ff;
			int yy = v[j].ff.ss;
			//if(xx == ind.ff and yy==ind.ss and v[j].ss == d) ig = true;
			if(xx == ind.ff and yy==ind.ss){
				double d2 = abs(v[j].ss-d);
				if (a!=0 and b!=0) d2 = ld(d2 / ld(sqrt((a*a)/(b*b) + 1.0)));
				dist[ind].pb(d2);
			}
		}
		v.pb({ind, d});
	}
	int ans = 0;

	for(auto it : dist){
		vector<double> paral = it.ss;
		sort(paral.begin(), paral.end());

		pii ind = it.ff;
		int xx = (ind.ss>=0) ? ind.ss : -ind.ss;
		int yy = (ind.ss>=0) ? -ind.ff : ind.ff;
		pii ind_p = {xx, yy};

		vector<double> perp = dist[ind_p];
		sort(perp.begin(), perp.end());

		int it1=0, it2=0;
		int s1 = paral.size(), s2 = perp.size();
//		cout << s1 << " "<< ans << endl;
//		cout << xx << " x " << yy << endl;
//		cout << ind.ff << " ind " << ind.ss << " " <<ans << " " <<s2<< endl;
//		for(auto x : paral)
///			cout << x << " ";
//		cout << endl;

		while(it1 != s1 and it2 != s2){
			if(!eq(paral[it1], perp[it2])){
				while(it2 != s2 and paral[it1] - perp[it2] > 1e-9) it2++;
				while(it1 != s1 and it2 != s2 and perp[it2] - paral[it1] > 1e-9) it1++;
				continue;
			}
			double d = paral[it1];
			int ig1 = 0;
			int ig2 = 0;
//			cout <<d << " "<< perp[it2] << " " << eq(d, perp[it2]) << endl;
			while(it2 != s2 and eq(d, perp[it2])){
			//cout << it2 << " " << paral[it1]  << " "<<paral[it2] << endl;
				ig2++;
				it2++;
			}
			while(it1 != s1 and eq(d, paral[it1])){
			//cout << it1 << " 2 " << paral[it1]  << " "<<paral[it2] << endl;
				ig1++;
				it1++;
			}
			ans += ig1*ig2;
		}
	}
	cout << ans/2 << endl;
	exit(0);
}
