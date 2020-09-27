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
	int ans =0, a;
	for(int i=0;i <5; i++){
		cin >> a; if(abs(a)%2==0) ans++; 
	}	
	cout << ans << " valores pares" << endl;
	
	
	
	exit(0);
}
