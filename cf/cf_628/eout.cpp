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
const int MAX = 1e6;
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
	crivo((int)1e5);
	vector<int> v;
	for(int i=0; i<pri.size(); i++){
		if(v.size()>(int)1e5) break;
		for(int j=i+1;j<pri.size(); j++){
			if(v.size()>(int)1e5) break;
			if(pri[i]*pri[j]>(int)1e6) break;
			v.pb(pri[i]*pri[j]);
		}
	}
	cout << v.size() << endl;
	for(int i=0;i <v.size(); i++) cout << v[i] << " ";
	cout << endl;
	
	
	
	exit(0);
}
