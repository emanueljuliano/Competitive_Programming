#include <bits/stdc++.h>
#define s second
#define f first
#define pb push_back
#define endl '\n'
using namespace std;


typedef long long ll;
typedef pair<int,int> pii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

unordered_set<int> FIB;
vector<int> fib;

void pre(){
	int a,b,c;
	a = 1;
	b = 1;
	c = a + b;
	FIB.insert(a);
	FIB.insert(c);
	fib.pb(1);
	fib.pb(2);
	while(c <= 1000000){
		a = b;
		b = c;
		c = a + b;
		FIB.insert(c);
		fib.pb(c);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	pre();

	vector<int> V(N);

	for(int i = 0; i < N; i++)
		cin >> V[i];

	map<int,int> M;

	for(int i = 0; i < N; i++){
		if(FIB.count(V[i])){
			M[V[i]] = i;
		}
	}


	for(auto x : M){
		auto it = lower_bound(fib.begin(), fib.end(),x.f);
		if(it == fib.begin() || it == fib.end() - 1){
			continue;
		}


	}

	return 0;
}
