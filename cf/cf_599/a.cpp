#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

typedef long long ll;

int main(){ _
	int n, k;
	cin >> k;
	for(int i=0; i<k; i++){
		cin >> n;
		vector <int> v;
		int a;
		for(int j=0; j<n; j++){
			cin >> a;
			v.push_back(a);
		}
		sort(v.begin(), v.end());

		int maxi = 0;
		for(int j=0; j<n; j++){
			int lado = min(v[j], (n-j));
			maxi = max(lado, maxi);
		}
		cout << maxi << endl;
	}


	exit(0);
}
