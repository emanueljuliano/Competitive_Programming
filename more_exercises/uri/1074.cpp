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
	for(int i=0;i <n; i++){
		int a; cin >> a;
		if(a==0) cout << "NULL" << endl;
		else if(a%2 and a>0) cout << "ODD POSITIVE" << endl;
		else if(a%2 and a<0) cout << "ODD NEGATIVE" << endl;
		else if(a%2==0 and a>0) cout << "EVEN POSITIVE" << endl;
		else cout << "EVEN NEGATIVE" << endl;
	}
	
	
	
	exit(0);
}
