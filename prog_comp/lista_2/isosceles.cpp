#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define f first
#define s second

typedef pair<int, int> ii;
typedef long long ll;

const int INF = 0x3f3f3f3f;

int main(){ _
	int n; cin >> n;
	vector<int> v(n);
	for(auto &i: v) cin >> i;

	int at = 0;
	for(int i=0;i <n; i++){
		v[i] = min(at+1, v[i]);
		at = v[i];
	}
	at = 0;
	for(int i=n-1;i+1; i--){
		v[i] = min(at+1, v[i]);
		at = v[i];
	}

	int maxi = 0;
	for(auto u : v) maxi = max(maxi, u);
	cout << maxi << endl;





	exit(0);
}
