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

char M[1010][1010];

int main(){ _
	int t; cin >> t;
	while(t--){
		int n, m; cin >> n >> m;
		for(int i=0;i <n; i++) for(int j=0; j<n; j++) cin >> M[i][j];

		if(m%2==1){
			cout << "YES" << endl;
			for(int i=0;i <=m; i++) cout << i%2+1 << " ";
			cout << endl;
			continue;
		}

		int a=-1, b=-1, c=-1;
		for(int i=0;i <n; i++) for(int j=0; j<n; j++) if(i!=j){
			if(M[i][j]==M[j][i]) a = i, b = j;
		}

		if(a!=-1){
			cout << "YES" << endl;
			vector<int> v = {a, b};
			for(int i=0;i <=m; i++) cout << v[i%2]+1 << " ";
			cout << endl;
			continue;
		}
		if(n==2){
			cout << "NO" << endl;
			continue;
		}

		a = -1, b = -1, c= -1;
		bool found = false;
		for(int i=0;i <n and !found; i++) for(int j=0; j<n and !found; j++)
			for(int k=0; k<n and !found; k++) if(i!=j and j!=k){
			if(M[i][j] == M[j][k]) a=i, b=j, c=k, found=true;
		}
		if(m%4==2){
			vector<int> v = {a, b, c, b};
			cout << "YES" << endl;
			for(int i=0;i <=m; i++) cout << v[i%v.size()]+1 << " ";
			cout << endl;
		}
		else{
			vector<int> v = {a, b, c, b};
			cout << "YES" << endl;
			for(int i=1;i <=m+1; i++) cout << v[i%v.size()]+1 << " ";
			cout << endl;
		}
	}
	
	
	
	exit(0);
}
