#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"

typedef long long ll;



int main(){	_
	int q, n;
	cin >> q;
	for(int i=0; i<q; i++){
		cin >> n;
		vector <int> a;
		for(int j=0; j<n; j++){
			int aux;
			cin >> aux;
			a.push_back(aux);
		}
		int resp = 1;
		sort(a.begin(), a.end());
		for(int j=0; j<a.size()-1; j++){
			if((a[j]+1) == a[j+1]) resp = 2;
		}
		cout << resp << endl;
	}


	exit(0);
}
