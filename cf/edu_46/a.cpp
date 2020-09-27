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
	int n; cin >> n;
	vector<string> a, b; 
	int l1=0, s1=0, m1=0, l2=0, s2=0, m2=0;
	for(int i=0;i <n; i++){
		string s; cin >> s;
		if(s=="M")m1++;
		else if(s=="S") s1++;
		else if(s=="L") l1++;
		else a.pb(s);
	}
	for(int i=0;i <n; i++){
		string s; cin >> s;
		
		
		if(s=="M")m2++;
		else if(s=="S") s2++;
		else if(s=="L") l2++;
		else b.pb(s);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int dif = abs(s1-s2) + abs(l1-l2) + abs(m1-m2);
	dif /=2;

	for(int i=0;i <a.size(); i++){
		if(a[i].size()<2) continue;
		if(a[i] != b[i]){
			for(int j=0; j<a[i].size(); j++){
				if(a[i][j] != b[i][j]) dif++;
			}
		}
	}
	cout << dif << endl;
	
	exit(0);
}
