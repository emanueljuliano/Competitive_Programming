#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

typedef long long ll;

int main(){ _

	int t;
	cin >> t;
	for(int i=0; i<t; i++){
		int n;
		cin >> n;
		vector <int> v[200200];
		int a;
		for(int j=1; j<=n; j++){
			cin >> a;
			v[a].push_back(j);
		}
		int mini = 200200;
		for(int j=1; j<=n; j++){
			if(v[j].size()>1)
				for(int k=0; k<v[j].size()-1; k++)
					mini = min(mini, v[j][k+1]-v[j][k]);
		}
		if(mini == 200200)
			cout << -1 << endl;
		else
			cout << mini+1 << endl;
	}


	exit(0);
}
