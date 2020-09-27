#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"

typedef long long ll;




int main(){ _
	int n, a;
	vector <int> v;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a;
		v.push_back(a);
	}
	ll menor=0, maior=0;
	sort(v.begin(), v.end());
	for(int i=0; i<v.size(); i++){
		if(i<v.size()/2) menor += v[i];
		else maior+= v[i];
	}

	ll resp = menor*menor + maior*maior;
	cout << resp << endl;


	exit(0);
}
