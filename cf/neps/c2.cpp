#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ld area(int a, int b, int c){
	ld p = ld(a+b+c)/2;
	if(a+b<=c or a+c<=b or b+c<=a) return -1;
	if(p-a<0 or p-b<0 or p-c<0) return -1;
	return sqrt(p)*sqrt(p-a)*sqrt(p-b)*sqrt(p-c);

}

int main(){ _
	int n; cin >> n;
	vector<int> v;
	for(int i=0;i <n; i++){
		int a; cin >> a;
		v.pb(a);
	
	}
	sort(v.begin(), v.end());
	ld ans = -1;
	int l1, l2, l3;
	for(int i=0;i <v.size()-2; i++){
		ld a = area(v[i], v[i+1], v[i+2]);
		if(ans<a){
			l1 = v[i];
			l2 = v[i+1];
			l3 = v[i+2];
			ans = a;
		}
	}
	//cout << ans << endl;
	cout << l1 << " " << l3 << " " << l2 << endl;
	
	
	
	exit(0);
}
