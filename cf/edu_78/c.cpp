#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define ff first
#define ss second
typedef long long ll;


int main(){ //_
	int t;
	cin >> t;
	for(int k=0; k<t; k++){
		int n;
		cin >> n;
		int dif=0;
		vector <int> v, dir, esq;
		for(int i=0; i<2*n; i++){
			int a;
			cin >> a;
			if(a==2) a=-1;
			dif+=a;
			v.pb(a);
		}
		dir.pb(v[n]);
		esq.pb(v[n-1]);
		for(int i=1; i<n; i++){ dir.pb(dir[i-1]+v[n+i]); esq.pb(esq[i-1]+v[n-i-1]);}
		
		if(dif==0){ cout << 0 << endl; continue;}
		//cout << dif << endl;
		
		if(dif<0){
			for(int i=0; i<n; i++){
				dir[i] = -dir[i];
				esq[i] = -esq[i];
			}
			dif = -dif;
		}
		vector <pair <int, int>> me, md;
		me.pb({0, 0});
		md.pb({0, 0});
		int ate = 0;
		int atd=0;
		for(int i=0; i<n; i++){

			if(esq[i]>me[ate].ff){
				me.pb({esq[i], i+1});
				ate++;
			}
			if(dir[i]>md[atd].ff){
				md.pb({dir[i], i+1});
				atd++;
			}
		}
		//cout << ate << " " << atd << endl;
		int ans = 2*n;
		if(atd>=dif){ atd=dif, ans = md[atd].ss; ate=0;}
		else{ate=dif-atd; ans = md[atd].ss + me[ate].ss;}
		//cout << md[atd].ss << " " << me[ate].ss << endl;
		//for(int i=0; i<atd; i++){
		//	if(md[atd].ff==dif){ atd=i; break;}
		//}
		//for(int i=0; i<ate; i++) if(me[ate].ff+md[atd].ff==dif){ate=i; break;}
		

		for(int i=ate; i<me.size(); i++){
			int so = md[atd].ff + me[i].ff;
			int ind = md[atd].ss + me[i].ss;
			//cout << "k " << so << endl;
			if(so==dif) ans = min(ans, ind);
			atd--;
			if(atd<0) break;
		}
		
		cout << ans << endl;
		
			
	}


	exit(0);
}
