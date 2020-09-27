#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second

typedef long long ll;
typedef float ld;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _

	int n; cin >> n; 
	ld endn = n, a, b;

	vector<ld> line(5e5+10);

	for(int i=0; i<n; i++) {
		cin >> a >> b;
		line[i] = a*b;
	}

	sort(line.begin(), line.begin()+n);

	ld sum = 0, now = 0;
	for(int i=0; i<n; i++){	
		now += line[i];
		sum += now;
	}

	cout << fixed << setprecision(20);
	cout << sum/endn << endl;

	return 0;
}
