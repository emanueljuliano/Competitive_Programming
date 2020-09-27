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
	vector<int> fat(11);
	fat[0] = 1;
	for(int i=1; i<=10; i++) fat[i] = fat[i-1]*i;
	
	int n; cin >> n;
	int at = 10;
	int ans = 0;
	while(n>0){
		if(n<fat[at]) at--;
		else{
			n -= fat[at];
			ans++;
		}
	}	
	cout << ans << endl;
	
	
	
	exit(0);
}
