#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const int LINF = 0x3f3f3f3f3f3f3f3f;


int main(){ _
		
	int maxi = 100;
	int n; cin >> n;
	int at = 100;

	for(int i=0;i <n; i++){
		int a; cin >> a; at+= a;
		maxi = max(maxi, at);
	}
	cout << maxi << endl;
	
	
	exit(0);
}
