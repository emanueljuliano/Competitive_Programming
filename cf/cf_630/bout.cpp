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

bool pri(int x){
	for(int i=2; i*i<=x; i++){
		if(x%i==0) return false;
	}
	return true;
}

int main(){ _
	cout << 1000;
	vector<int> v;
	for(int i=0; i<1000; i++){
		if(!pri(i)) v.pb(i);
	}
	cout << v.size() << endl;
	for(int i=0; i<v.size(); i++)
		cout << v[i] << " ";
	
	
	exit(0);
}
