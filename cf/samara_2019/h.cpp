#include <bits/stdc++.h>

using namespace std;

//#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int solve(int p, vector<int> v, vector<int> q){
	int a=0, b=0;
	if(v.size()==1) return v[0];
	vector<int> w, q2, q3;
	for(int i=0; i<v.size(); i++){
		if(v[i]&(1<<p)) a++;
	}
	for(int i=0; i<q.size(); i++){
		cout << "? " << q[i] << " " <<  p << endl;
		int x; cin >> x;
		q2.pb(x);
		b+=x;
	}
	if(a!=b){  // impar esta sumido
		for(int i=0;i <v.size(); i++){
			if(v[i] & (1<<p)) w.pb(v[i]);
		}
		for(int i=0;i <q2.size(); i++){
			if(q2[i]) q3.pb(q[i]);
		}
	}
	else{
		for(int i=0;i <v.size(); i++){
			if(!(v[i] & (1<<p))) w.pb(v[i]);
		}
		for(int i=0;i <q2.size(); i++){
			if(!q2[i]) q3.pb(q[i]);
		}
	}
	return solve(p+1, w, q3);
}

int main(){ 
	int n; cin >> n;
	vector<int> v, q;
	for(int i=0;i <=n; i++){
		v.pb(i);
		if(i!=0) q.pb(i);
	}
	int ans = solve(0, v, q);
	cout << "! " << ans << endl;	
	
	
	exit(0);
}
