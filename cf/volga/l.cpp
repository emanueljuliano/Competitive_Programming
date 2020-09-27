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
	int n, k; cin >> n >> k;
	string s1, s2; cin >> s2 >> s1;
	int m1=-1, m2=-1, g1=-1, g2=-1;
	for(int i=0;i <n; i++){
		if(s1[i]=='1' and m1==-1) m1 = i;
		if(s1[i]=='1') g1 = i;
		if(s2[i]=='1' and m2==-1) m2 = i;
		if(s2[i]=='1') g2 = i;
	}
	if(m1==-1){
		int p1 = 2;
		int p2 = (m2+1+g2+1)/2;
		int ans = max(abs(m2+1-p2), abs(g2+1-p2));
		cout << ans << endl;
		cout << p1 << " " << p2 << endl;
	}
	else if(m2==-1){
		int p1 = 1;
		int p2 = (m1+1+g1+1)/2;
		int ans = max(abs(m1+1-p2), abs(g1+1-p2));
		cout << ans << endl;
		cout << p1 << " " << p2 << endl;
	}
	else{
		int ans = INF;
		int p1=1, p2=g1;
		for(int i=g1; i>=0; i--){
			if(max(g1-i, k+g2+1+i+1) < ans){
				p1 = 1; p2 = i+1; ans = max(g1-i, k+g2+1+i+1);
			}
		}
		for(int i=g2; i>=0; i--){
			if(max(g2-i, k+g1+1+i+1) < ans){
				p1 = 2; p2 = i+1; ans = max(g2-i, k+g1+1+i+1);
			}
		}
		cout << ans << endl;
		cout << p1 << " " << p2 << endl;

	}
	
	
	
	exit(0);
}
