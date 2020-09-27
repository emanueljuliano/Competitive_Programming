#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	int t, n;
	cin >> t;
	int v[300200];
	int ans[300200];
	for(int k=0; k<t; k++){
		cin >> n;
		for(int i=0; i<=n; i++){ ans[i] = 0;v[i]=0;}
		int a;
		for(int i=0; i<n; i++){
			cin >> a;
			v[a] = i;
		}

		int mini = v[1];
		int maxi = v[1];
		for(int i=0; i<n; i++){
			mini = min(mini, v[i+1]);
			maxi = max(maxi, v[i+1]);
			if(maxi-mini == i){
				cout << 1;
			}
			else
				cout << 0;
		}
		cout << endl;
	}


	exit(0);
}
