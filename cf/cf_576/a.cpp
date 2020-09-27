#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

typedef long long ll;

int main(){ _

	int k;
	cin >> k;
	for(int i=0; i<k; i++){
		int n, s, a, b;
		cin >> n >> s >> a >> b;
		cout << min(n-1, abs(a-b)+s) << endl;

	}


	exit(0);
}
