#include <bits/stdc++.h>

using namespace std;

#define debbuging true
#define debug if(debbuging) cout
#define _ if(!debbuging) ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


int main(){ _
	int n, m; cin >> n >> m;
	
	if((n%2 and m%2) or (n==1 and m>2) or (n>2 and m==1)){
		cout << 1 << endl;
		cout << n << " " << m << " " << 1 << " " << 1 << endl;
		
		for(int i=0;i <n; i++) {
			if(i%2==0) for(int j=0; j<m; j++) cout << i+1 << " " << j+1 << endl;
			else for(int j=m-1; j+1; j--) cout << i+1 << " " << j+1 << endl;
		}
		cout << 1 << " " << 1 << endl;
	}
	else if(n%2==0){
		cout << 0 << endl;
		cout << 1 << " " << 1 << endl;
		for(int i=0;i <n; i++) {
			if(i%2==0) for(int j=1; j<m; j++) cout << i+1 << " " << j+1 << endl;
			else for(int j=m-1; j; j--) cout << i+1 << " " << j+1 << endl;
		}
		for(int i=n-1; i+1; i--) cout << i+1 << " " << 1 << endl;
	}
	else if(m%2==0){
		cout << 0 << endl;
		cout << 1 << " " << 1 << endl;
		for(int j=0;j <m; j++) {
			if(j%2==0) for(int i=1; i<n; i++) cout << i+1 << " " << j+1 << endl;
			else for(int i=n-1; i; i--) cout << i+1 << " " << j+1 << endl;
		}
		for(int j=m-1; j+1; j--) cout << 1 << " " << j+1 << endl;	
	}


	exit(0);
}
