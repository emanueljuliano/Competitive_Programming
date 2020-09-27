#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

typedef long long ll;

#define ss second
#define ff first
typedef pair<int, int> pii;

int ord(pii a, pii b){
	if(a.ss==b.ss)
		return a.ff>b.ff;
	return a.ss>b.ss;
}

int main(){ _

	int t;
	cin >> t;
	for(int k=0; k<t; k++){
		
		int n, m;
		cin >> n;
		vector<int> mon;
		int a, b;
		int maxi_mon = -1;
		for(int i=0; i<n; i++){
			cin >> a;
			maxi_mon = max(maxi_mon, a);
			mon.push_back(a);
		}
	
		vector <pair<int, int> > hero_aux;
		vector <pair<int, int> > hero;
		bool tem_maior = false;		

		cin >> m;
		for(int i=0; i<m; i++){
			cin >> a >> b;
			if(a>=maxi_mon) tem_maior = true;
			hero_aux.push_back({a, b});
		}
		sort(hero_aux.begin(), hero_aux.end(), ord);		
	
		if(!tem_maior){
			cout << -1 << endl;
			continue;
		}

		vector<int> v;
		a = hero_aux[0].ff; b=hero_aux[0].ss;
		hero.push_back(hero_aux[0]);
		v.push_back(a);	
		for(int i=1; i<m; i++){
			if(hero_aux[i].ff>a){
				a = hero_aux[i].ff;
				b = hero_aux[i].ss;
				hero.push_back(hero_aux[i]);
				v.push_back(a);
			}	
		}

		int at=0, ans = 1, c=0;

		for(int i=0; i<mon.size(); i++){
			c+=1;
			if(hero[at].ff >= mon[i])
				if(c<=hero[at].ss)
					continue;
				else{
					ans+=1;
					c=1;
					at = lower_bound(v.begin(), v.end(), mon[i]) - v.begin();
					if(hero[at].ff<mon[i])
						at =  upper_bound(v.begin(), v.end(), mon[i]) - v.begin();
				}
			else{
				at = lower_bound(v.begin(), v.end(), mon[i]) - v.begin();
				if(hero[at].ff<mon[i])
					at =  upper_bound(v.begin(), v.end(), mon[i]) - v.begin();
				
				if(hero[at].ss >= c)
					continue;
				else{
					c=1;
					ans+=1;
				}	
			}	
		}
		cout << ans << endl;

	}

	exit(0);
}
