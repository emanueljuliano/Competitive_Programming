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
	int pos=0, neg=0;
	vector<int> v;
	for(int i=0;i <n; i++){
		int a; cin >> a; v.pb(a);
		if(a%2 and a<0) neg++;
		if(a%2 and a>0) pos++;
	}
	int at = 0;
	int d =0;
	for(int i=0;i <n; i++){
		if(v[i]%2==0) v[i] = v[i]/2;
		else {
			if(d>=0 and v[i]>0) v[i] = v[i]/2, d--;
			else if(d>=0 and v[i]<0) v[i] = v[i]/2-1, d--;
			else if(d<0 and v[i]>0) v[i] = v[i]/2+1, d++;
			else if(d<0 and v[i]<0) v[i] = v[i]/2, d++;
		}
	}
	for(auto k : v) cout << k << endl;
	
	
	
	exit(0);
}
