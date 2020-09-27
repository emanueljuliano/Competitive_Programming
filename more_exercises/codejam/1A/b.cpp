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
	int t; cin >> t;
	int cs = 0;
	while(t--){
	cs++;
		cout << "Case #" << cs << ":" << endl;
		int n; cin >>  n;
		int soma = 1;
		int at = 0;
		for(int i=1;i <=n; i++){
			if(soma+i>n) break;
			soma += i;
			at++;
		}
		int ts = 0;
		if(n<=3){
			for(int i=1; i<=n; i++){
				cout << i << " 1" << endl;
			}
		}
		else{
			cout << "1 1" << endl;
			for(int i=1;i <=at; i++){
				cout << i+1 << " 2" << endl;
			}
			for(int i=0; i<n-soma; i++){
				cout << i+at << " 1" << endl;
			}
		}
	}
	
	
	
	exit(0);
}
