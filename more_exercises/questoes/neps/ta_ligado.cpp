#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"

int main(){ _
	int n, m, a, b, c;
	cin >> n >> m;
	vector <set <int> > v(100100);
	for(int i=0; i<m; i++){
		cin >> a >> b >> c;
		if(a==0){
			if(v[b].count(c))
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
		else{
			v[b].insert(c);
			v[c].insert(b);
		}
	}
}
