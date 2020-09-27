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

const int MAX=1010;
int divi[MAX];
vector<int> pri;
void crivo(int lim) {
	for (int i = 1; i <= lim; i++) divi[i] = 1;

	for (int i = 2; i <= lim; i++) if (divi[i] == 1){
		pri.pb(i);
		for (int j = i; j <= lim; j += i) divi[j] = i;
		}
}

int main(){ _
	int t; cin >> t;
	crivo(MAX-10);
	while(t--){
		int n; cin >> n;
		vector<int> v;
		for(int i=0; i<n; i++){
			int a; cin >> a; v.pb(a);
		}
	
		int c = 0;
		vector<int> cor(n, -1);
		bool flag = true;
		for(int i=0; i<pri.size(); i++){
			flag = true;
			for(int j=0; j<n; j++){
				if(cor[j]==-1 and v[j]%pri[i]==0){
					if(flag){c++, flag=false;}
					cor[j] = c;
				}
			}
		}
		cout << c << endl;
		for(int i=0; i<n; i++){
			cout << cor[i] << " ";
		}
		cout << endl;
	
	}
	
	
	
	exit(0);
}
