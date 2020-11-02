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

bool val(int a, int b, int c, int m){
	if(c>m) return false;
	if(a>m){	
		int poe = m-c;
		poe = min(poe, b);
		b -= poe;
		c += poe;

		int tira = a-m;
		b += tira;
		a -= tira;
		return max({a, b, c}) <= m;
	}
	else{
		int poe = m-a;
		b -= poe; a += poe;
		poe = m-c;
		b -= poe; c += poe;
		return max({a, b, c}) <= m;
	}
}


int main(){ _
		
	int t; cin >> t;
	while(t--){
		int a, b, c;
		cin >>a  >> b >> c;
		if(a<c) swap(a, c);
		int l = min({a, b, c}), r = max({a, b, c});
		while(l<r){
			int m = (l+r)/2;
			if(val(a, b, c, m)) r = m;
			else l = m+1;
		}
		cout << l << endl;
	}
	
	
	exit(0);
}
