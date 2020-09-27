#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	int t;
	cin >> t;
	for(int x=0; x<t; x++){
		int n, k1, k2;
		cin >> n >> k1 >> k2;
		int maxi=0, m2=0;
		for(int i=0; i<k1; i++){
			int a;
			cin>>a;
			maxi = max(maxi, a);
		}for(int i=0; i<k2; i++){
			int a;
			cin >>a;
			m2 = max(a, m2);
		}
		if(maxi>m2)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	

	exit(0);
}
