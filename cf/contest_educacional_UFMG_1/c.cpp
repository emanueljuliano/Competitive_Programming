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
	string s; cin >> s;
	
	auto val = [&](int x){
		for(int c='a';c <='z'; c++){
			int at = 0;
			bool has = true;
			for(int i=0;i<x; i++) at += (s[i]==c);
			if(!at) has = false;
			
			for(int i=0; i<s.size()-x; i++){
				at -= (s[i]==c);
				at += (s[i+x]==c);
				if(!at) has = false;
			}
			if(has) return true;
		}
		return false;
	};

	int l = 1, r = s.size();
	while(l<r){
		int m = (l+r)/2;
		if(val(m)) r = m;
		else l = m+1;
	}
	cout << l << endl;

	exit(0);
}
