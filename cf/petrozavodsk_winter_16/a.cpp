#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;
typedef double ld;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int read_int() {
    bool minus = false;
    int result = 0;
    char ch;
    ch = getchar();
    while (1) {
        if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar();
    }
    if (ch == '-') minus = true;
    else result = ch-'0';
    while (1) {
        ch = getchar();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus) return -result;
    else return result;
}

int main(){
	int n; cin >> n;

	vector M(n, vector<ld>(n));
	vector M2(n, vector<int>(n));
	for(auto &u : M2) for(auto &c : u) c = read_int();	
	for(int i=0; i<n; i++) for(int j=0; j<n; j++) M[i][j] = M2[i][j];

	vector<int> y2(n), y(n), old(n);
	vector<ld> cur(n), prop(n);
	for(auto &i : y2) i = read_int();
	for(auto &i : y) i = read_int();

	for(int i=0;i <n; i++) old[i] = y2[i];
	for(int i=0; i<n; i++) for(int j=0; j<n; j++) old[i] += M2[i][j];

	for(int k=0;k <7; k++){
		//for(int i=0;i <n+1; i++) {for(int j=0; j<n; j++) cout << M[i][j] << " "; cout << endl;}

		for(int i=0;i <n; i++) {
			cur[i] = y[i];
			for(int j=0; j<n; j++) cur[i] += M[i][j];
			prop[i] = cur[i]/old[i];
		}
		for(int i=0;i <n; i++) for(int j=0; j<n; j++) M[i][j] = M2[i][j]*prop[j];
	}
	for(int i=0;i <n; i++) {
		cur[i] = y[i];
		for(int j=0; j<n; j++) cur[i] += M[i][j];
	}

	cout << setprecision(8) << fixed;
	for(int i=0;i <n; i++) cout << cur[i] << " ";
	cout << endl;

	exit(0);
}
