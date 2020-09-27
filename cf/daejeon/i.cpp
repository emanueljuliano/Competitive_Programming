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

vector<int> pi(vector<int> s) {
	vector<int> p(s.size());
	for (int i = 1, j = 0; i < s.size(); i++) {
		while (j and s[j] != s[i]) j = p[j-1];
		if (s[j] == s[i]) j++;
		p[i] = j;
	}
	return p;
}

int main(){ _
	int n; cin >> n;
	vector<int> v;
	for(int i=0;i <n; i++){
		int a; cin >> a; v.pb(a);
	}
	reverse(v.begin(), v.end());
	pi(v);
	int p = 1;
	int k = n-1;
	vector<int> w = pi(v);
	for(int i=0;i <n; i++){
		if(k+p > n-1-i+(i+1-w[i])){
			k = n-1-i;
			p = i+1-w[i]; 
		}
	}
	cout << k << " " << p<< endl;



	exit(0);
}
