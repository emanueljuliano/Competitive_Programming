#include <bits/stdc++.h>

using namespace std;

#define pb push_back


int main(){
		
	int n;
	cin >> n;
	vector<int> v;
	for(int i=0; i<n; i++){
		int s;
		cin >> s;
		for(int j=0; j<s; j++){
			int a;
			cin >> a;
			if(s%2 and j==(s/2))
				v.pb(a);
		}
	}
	sort(v.begin(), v.end());
	ll a = b = 0;
	for(int i=0; i<v.size(); i++){
		if(i%2)
			a+=v[i];
		else
			b+=v[i];
	}
	cout << a << " " << b << endl;
}
