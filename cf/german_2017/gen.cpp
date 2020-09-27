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
	int n=800, m=800, m2=50;;
	cout << n << " " << m << endl;
	for(int i=0; i<m-m2; i++){
		cout << i+1 << " " << (i+1)%n+1 << " " << 5.0 << endl;
	}
	for(int i=m-m2; i<m; i++){
		cout << i+1 << " " << (i+1)%n+1 << " " << 0.0001 << endl;
	}


	
	
	
	exit(0);
}
