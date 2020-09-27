#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;

int main(){ _
	int n; cin >> n;
	string s; cin >> s;
	vector<int> maxi(27, 0);
	vector<int> dp(n, 1);
	
	int ans = 1;
	for(int i=0; i<n; i++){
		int c = s[i] -'a';
		int aux = 0;
		for(int j=c+1; j<26; j++)
			aux = max(aux, maxi[j]);
		aux++;
		dp[i] = aux;
		maxi[c] = aux;
		ans = max(ans, aux);
	}
	
	cout << ans << endl;
	for(int i=0; i<n; i++){
		cout << dp[i] << " ";
	}
	cout << endl;

	exit(0);
}
