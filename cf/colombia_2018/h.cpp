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

bool bi(int x){
	bool ret = false;
	if(x%4==0) ret = true;
	if(x%100==0) ret = false;
	if(x%400==0) ret = true;
	return ret;
}


int main(){ _
	int n; cin >> n;
	int d = 6;
	int y = 1867;
	for(int i=0; i<n; i++){
		y++;
		if(bi(y)) d+=2;
		else d++;
	}
	vector<string> v = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
	cout << v[d%7] << endl;
	
	
	
	exit(0);
}
