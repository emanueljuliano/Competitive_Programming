#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	ll n, m , k; cin >> n >> m>>k;
	ll maxi = 4*n*m - 2*n - 2*m;
	if(k>maxi) return cout << "NO" << endl, 0;
	
	cout << "YES" << endl;
	
	ll ans = 1;
	vector<pair<int, string>> v;
	
	if(m==1){
		cout << 2 << endl;
		cout << n-1 << " D" << endl;
		cout << n-1 << " U" << endl;
		exit(0);
	}
	if(n==1){
		cout << 2 << endl;
		cout << m-1 << " R" << endl;
		cout << m-1 << " L" << endl;
		exit(0);
	}

	// m*r
	if(k<m){
		cout << ans << endl;
		return cout << k << " R" << endl, 0;
	}
	ans++;
	k-=(m-1);
	v.pb({m-1, "R"});
	
	// m*l
	if(k<m){
		cout << ans << endl;
		cout << m-1 << " R" << endl;
		cout << k << " L" << endl;
		exit(0);
	}
	k-=(m-1);
	ans++;
	v.pb({m-1, "L"});

	// end
	
	// repeat n-1
	for(int i=0; i<n-1; i++){
		if(k==0) break;
		// d
		if(k>0){v.pb({1, "D"}); k--;}
		
		// m-1 * rud
		if(k>= 3*(m-1)){
			v.pb({m-1, "RUD"});
			k-= 3*(m-1);
		}
		else{
			if(k>=3) v.pb({k/3, "RUD"});
			k -= 3* (k/3);
			if(k==1){
				v.pb({1, "R"});
			}
			if(k==2){
				v.pb({1, "RU"});
			}
			k=0;
		}
		
		// m-1 * l
		if(k>= m-1){
			v.pb({m-1, "L"});
			k -= m-1;
		}
		else{
			if(k>0) v.pb({k, "L"});
			k=0;
		}
	}
	
	if(k==0){
		cout << v.size() << endl;
		for(int i=0; i<v.size(); i++){
			cout << v[i].first << " " << v[i].second << endl;
		}
		exit(0);
	}

		
	//n*u
	v.pb({k, "U"});

	cout << v.size() << endl;
	for(int i=0; i<v.size(); i++){
		cout << v[i].first << " " << v[i].second << endl;
	}

	exit(0);
}
