#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	int t;
	cin >> t;
	int v[200200];
	for(int j=0; j<t; j++){
		int n;
		cin >> n;
		for(int i=0; i<n; i++){
			v[i];
		}
		set <int> s;	
		sort(v, v+n, greater<int>());
		for(int i=0; i<n; i++){
			int soma = 0;
			while(v[i]/2 == 0){
				soma += 1;
				v[i] /= 2;
			}
		}
		
	}


	exit(0);
}
