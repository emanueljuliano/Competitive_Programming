#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define ff first
#define ss second

typedef long long ll;


int main(){ _
	int n;
	cin >> n;
	vector <pair<int, int>> v, w;
	for(int i=0; i<n; i++){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		v.pb({a, b});
		w.pb({c, d});
	}
	sort(v.begin(), v.end());
	sort(w.begin(), w.end());
	set <int> s1;
	for(int i=0; i<v.size()-1; i++){
		if(v[i].ss>=v[i+1].ff){
			s1.insert(i);
		}
	}
	set <int> s2;
	for(int i=0; i<w.size()-1; i++){
		if(w[i].ss>=w[i+1].ff){
			s2.insert(i);
		}
	}
//	for(auto i : s1)
//		cout <<i << " ";
	if(s2==s1)
		cout << "YES" << endl;
	else
		cout <<"NO" << endl;

	exit(0);
}
