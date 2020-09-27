#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	int n, m;
	cin >> n >> m;
	vector <int> v, w, aux1, aux2;
	for(int i=0; i<n; i++){
		int a;
		cin >> a;
		v.pb(a);
	}
	multiset <int> certo;
	for(int i=0; i<n; i++){
		int a;
		cin >> a;
		w.pb(a);
		certo.insert(a);
	}
	aux1 = v;
	sort(aux1.begin(), aux1.end());
	aux2 = w;
	sort(aux2.begin(), aux2.end());
	
	set<int> tried;
	int ans=0;
	for(int i=0; i<n; i++){
		if(!tried.count(aux2[i])){
			tried.insert(aux2[i]);
			int dif = (aux2[i]-aux1[0] + m)%m;
			multiset <int> esse;
			for(int j=0; j<aux1.size(); j++){
				esse.insert((aux1[j]+dif)%m);
			}
			if(esse==certo) ans=dif;
		}
	}
	

	cout << ans << endl;
	exit(0);
}
