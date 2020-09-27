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
	int s = 0;
	string t; cin >> t;
	int d = 0;
	for(int i=0;i <n; i++){
		if(i<n/2 and t[i]!='?') s+= t[i]-'0';
		else if(i>=n/2 and t[i]!='?') s-= t[i]-'0';
		else if(i<n/2 and t[i]=='?') d++;
		else if(i>=n/2 and t[i]=='?') d--;
	}
	if(s==0){
		if(d==0) cout << "Bicarp" << endl;
		else cout << "Monocarp" << endl;
	}
	else if(s>0 and d>0) cout << "Monocarp" << endl;
	else if(s<0 and d<0) cout << "Monocarp" << endl;
	else{
		s = abs(s); d = abs(d);
		if(s%9!=0) cout << "Monocarp" << endl;
		else if(s/9 != d/2) cout << "Monocarp" << endl;
		else cout << "Bicarp" << endl;
	}		


	
	
	
	exit(0);
}
