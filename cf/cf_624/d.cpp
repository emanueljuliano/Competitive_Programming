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
	int t; cin >> t;
	while(t--){
		int a, b, c; cin >> a>> b >> c;
		int ans=a+b+c-3, a1=1, b1=1, c1=1;
		for(int i=1; i<=4*b; i++){
			for(int j=i; j<=4*c; j+=i){
				int x = c/j * j;
				int y = (c-1+j)/j * j;
				if(c-x > y-c) x = y;
				int dif = abs(a-i) + abs(b-j) + abs(c-x);
				if(dif<ans){
					ans = dif;
					a1 = i;
					b1 = j;
					c1 = x;
				}
			}
		}
		cout << ans << endl;
		cout <<a1 << " " << b1 << " " << c1 << endl;
	
	}
	
	
	
	exit(0);
}
