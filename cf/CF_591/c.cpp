#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

typedef long long ll;

ll z, mmc, x, a, y, b, q, n;
ll k;

bool consigo(int tam, vector<int> p){
	ll soma=0;
	int tam_mmc = tam/mmc;
	int tam_a = tam/a - tam_mmc;
	int tam_b = tam/b - tam_mmc;
	
	for(int j=0; j<p.size(); j++){
		if(tam_mmc>0){ soma += z*p[j]; tam_mmc--;}
		else if(tam_a>0){ soma+=x*p[j]; tam_a--;}
		else if(tam_b>0){ soma+= y*p[j]; tam_b--;}
	}
	if(soma>=k) return true;
	return false;	
}

int main(){ _
	cin >> q;
	for(int i=0; i<q; i++){
		cin >> n;
		int aux;
		vector <int>  p;
		for(int j=0; j<n; j++){
			cin >> aux;
			p.push_back(aux); 
		}
		sort(p.rbegin(), p.rend());
		cin >> x >>a;
		cin >> y >> b;
		if(x<y){swap(x, y); swap(a, b);}
		z= x+y;
	
		mmc = a*b/__gcd(a, b);
		
		cin >> k;
		k*=100;
		int ini=0, end = n;
		int mid = (ini+end)/2;
		if(!consigo(end, p)){ cout << -1 << endl; continue;}
		while(mid!=end and mid!=ini){
			if(consigo(mid, p))
				end = mid;
			else
				ini = mid;
			mid = (ini+end)/2;
		}
		if(consigo(ini, p)) cout << ini << endl;
		else cout << end << endl;
	}
}
