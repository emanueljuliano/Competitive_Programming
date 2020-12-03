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
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MAX = 11;

int M[MAX][MAX];

bool val(ii a){
	return a.f>=0 and a.s>=0 and a.f<10 and a.s<10;
}

int main(){ _
		
	int n; cin >> n;
	for(int j=0;j <n; j++){
		int d, l, r, c; cin >> d >> l >> r >> c; c--, r--;
		if(!d){
			ii a = {r, c}, b = {r, c+l-1};
			if(!val(b)) return cout << "N" << endl, 0;
			for(int i=c; i<=c+l-1; i++) M[r][i]++;
		}
		else{
			ii a = {r, c}, b = {r+l-1, c};
			if(!val(b)) return cout << "N" << endl, 0;
			for(int i=r; i<=r+l-1; i++) M[i][c]++;	
		}
	}

	for(int i=0;i <10; i++)
		for(int j=0; j<10; j++)
			if(M[i][j]>1) return cout << "N" << endl, 0;
	cout << "Y" << endl;
	
	
	exit(0);
}
