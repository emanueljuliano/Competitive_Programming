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
	vector<char> v = {'R', 'O', 'Y', 'G', 'B', 'I', 'V'};
	for(int i=0;i <n-3; i++) cout << v[i%4];
	cout << "BIV" << endl;
	
	exit(0);
}
