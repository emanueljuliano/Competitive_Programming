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
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

ii rpt(){
	int a = rng();
	int b = rng();
	return {abs(a)%101, abs(b)%101};
}

int main(){ _
	int n = 150, m = 150;
	cout << "Companions: ";
	for(int i=0;i <n; i++){
		ii p= rpt();
		cout << "("<<p.f<<", "<<p.s<<")";
		if(i!=n-1) cout << " ";
	}
	cout << endl;
	cout << "Orcs: ";
	for(int i=0;i <m; i++){
		ii p= rpt();
		cout << "("<<p.f<<", "<<p.s<<")";
		if(i!=n-1) cout << " ";
	}
	cout << endl;
	
	
	exit(0);
}
