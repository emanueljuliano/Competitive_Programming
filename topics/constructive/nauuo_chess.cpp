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
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


int main(){ _
	int n; cin >> n;
	cout << n/2+1 << endl;
	for(int i=0;i <n; i++){
		cout << i/2+1 << " " << (i+1)/2+1 << endl;
	}
	
	
	
	exit(0);
}
