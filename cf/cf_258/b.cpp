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
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	int n; cin >>n ;
	vector<int> v(n);
	for(auto &i : v) cin >> i;

	int l=-1, r=-1;
	bool show = true;
	for(int i=1; i<n; i++){
		if(v[i]<v[i-1] and r!=-1) show=false;
		else if(v[i]<v[i-1] and l==-1) l = i-1;
		else if(v[i]>v[i-1] and l!=-1 and r==-1) r = i-1;
	}
	if(l==-1) l = 0, r = 0;
	else if(r==-1) r =n-1; 
	
	vector<int> nv;
	for(int i=0;i <l; i++) nv.pb(v[i]);
	for(int i=r;i>=l; i--) nv.pb(v[i]);
	for(int i=r+1;i <n; i++) nv.pb(v[i]);
	sort(v.begin(), v.end());
	if(v != nv) show = false;

	if(!show) cout << "no" << endl;
	else{
		cout << "yes" << endl;
		if(l==-1) cout << "1 1" << endl;
		else cout << l+1 << " " << r+1 << endl;
	}



	exit(0);
}
