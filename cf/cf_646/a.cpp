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
	while(t--){
		int n, x; cin >> n >> x;
		int im=0, p=0;
		for(int i=0;i <n; i++){
			int a; cin >> a;
			if(a%2)im++;
			else p++;
		}
		if(!im) cout << "No" << endl;
		else if(x>=im){
			x -= im;
			if(im%2==0) x++;
			if(x>p){
				cout << "no" << endl;
			}
			else cout << "Yes" << endl;
		}
		else{
			if(x%2) cout << "Yes" << endl;
			else{
				if(p) cout << "Yes" << endl;
				else cout << "No" << endl;
			}
		}
		
	}
	
	
	
	exit(0);
}
