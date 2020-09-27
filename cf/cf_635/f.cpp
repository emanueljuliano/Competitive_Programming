#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
//#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;
typedef double ld;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ld eps = 1e-1;

int val(int x){
	if(x==0) return 0;
	return  (1+sqrt((ld)1 + 8*x))/2 + eps;
}

int main(){ _
	int n, x, y; cin >> n;
	cin >> x >> y;
	vector<int> ans(n+10, 0);
	vector<int> v(n+10, 0), w(n+10, 0);
	v[0]=x;
	w[1]=y;
	vector<int> ant;
	ant.pb(x);
	int it=0;
	for(int i=n-1;i >2; i--){
		cout << "+ " << i<< endl;
		ll a, b; cin >> a >> b;
		it++;
		v[i]=a;
		w[i]=b;
		ant.pb(a);
		ans[i] = val(ant[it] - ant[it-1]);
	}
//	for(int i=3; i<=n-1; i++) cout << ans[i] << " ";
//	cout << endl;
	int a, b;
	cout << "+ 1" << endl;
	cin >> a >> b;
	v[1]=a; w[1]=b;
	int b11 = b;
	ant.pb(a);
	it++;
	ans[1] = val(ant[it] - ant[it-1]);
	int a11 = w[1] - w[3];

	cout << "+ 2" << endl;
	cin >> a >> b;
	v[2]=a; w[2]=b;
	ant.pb(a);
	it++;
	ans[2] = val(ant[it] - ant[it-1]);

	cout << "+ 1" << endl;
	cin >> a >> b;
	ant.pb(a);
	v[1]=a; w[1]=b;
	it++;
	ans[1] =  val(ant[it] - ant[it-1]);
	if(ans[1]==0) ans[1]++;

	int a12 = w[1] - w[2];
//	cout << a11 << " a1x " << a12 << endl;
	ans[3] = a12 - a11;
	ans[2] = a12/(ans[3]);

//	cout << w[2] << " " << b11 << endl;
	ans[4] = (w[2]-b11  - ans[1]*ans[3])/ans[3];
//	cout << "ans 1 to 4 = " << ans[1] << " " << ans[2] << " " << ans[3] << " " << ans[4] << endl;	
	ans[1]--;
	ans[2]--;
	for(int i=3; i<=n-2; i++){
		ans[i]--;
//		cout << "I = " << i<< endl;
//		cout << w[i] << " <- w ->" << w[i+1] << " i-2 " << ans[i-2] << " i-1 " << ans[i-1] << " i+1 " << ans[i+1] << endl;
		ans[i+2] = (w[i]-w[i+1] - ans[i-2]*ans[i-1] - ans[i-1]*ans[i+1])/ans[i+1];
//		cout << ans[i+2] << " = (" << w[i]-w[i+1] << "-" << ans[i-2]*ans[i-1] << "-" << ans[i-1]*ans[i+1]<< ")/" << ans[i+1] << endl;
	}
	ans[n-1]--;
	cout << "! ";
	for(int i=1;i <=n; i++){	
		cout << ans[i] << " ";
	}
	cout << endl;

	exit(0);
}
