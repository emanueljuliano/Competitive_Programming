#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	int n; cin >> n;
	string s; cin >> s;
	int cor[202];
	memset(cor, 0, sizeof(cor));
	for(int i=1; i<n; i++){
		cor[i] = -1;
		for(int j=0; j<i; j++){
			if(s[j]>s[i]){
				if(cor[j] == cor[i]){
					cout << "NO" << endl;exit(0);
				}
				cor[i] = !cor[j];
			}
		}
		if(cor[i]==-1) cor[i] = 0;
	}
	cout << "YES" << endl;
	for(int i=0; i<n; i++) cout << cor[i];
	cout << endl;

	exit(0);
}
