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

ii rec(int n, int m, int inv){
//	cout << n << " " << m << " " << inv << endl;
	if(n==1) return {1, 1};

	
	ii ret; int m1=inv, m2=inv;
	if(inv==0) m1 = (m1+1)%4, m2 = (m2+3)%4;
	if(inv==1) m1 = (m1+3)%4, m2 = (m2+1)%4;
	if(inv==2) m1 = (m1+1)%4, m2 = (m2+3)%4;
	if(inv==3) m1 = (m1+3)%4, m2 = (m2+1)%4;
	

	if(m<=n*n/4) ret = rec(n/2, m, m1);
	else if(m<=n*n/2) ret = rec(n/2, m-n*n/4, inv);
	else if(m<=n*n/4*3) ret = rec(n/2, m-n*n/2, inv);
	else if(m<=n*n) ret = rec(n/2, m-n*n/4*3, m2);
	
	if(inv==0){
		if(m<=n*n/4){}
		else if(m <=n*n/2) ret.s += n/2;
		else if(m<=n*n/4*3) ret.f += n/2, ret.s += n/2;
		else if(m<=n*n) ret.f += n/2;		
	}
	if(inv==1){
		if(m<=n*n/4){}
		else if(m <=n*n/2) ret.f += n/2;
		else if(m<=n*n/4*3) ret.f += n/2, ret.s += n/2;
		else if(m<=n*n){
			ret.s += n/2;		
		}
	}
	if(inv == 2){
		if(m<=n*n/4){ret.f += n/2, ret.s += n/2;}
		else if(m <=n*n/2) ret.f += n/2;
		else if(m<=n*n/4*3) {}
		else if(m<=n*n) ret.s += n/2;			
	}
	if(inv == 3){
		if(m<=n*n/4){ret.f += n/2, ret.s += n/2;}
		else if(m <=n*n/2) ret.s += n/2;
		else if(m<=n*n/4*3) {}
		else if(m<=n*n) ret.f += n/2;			
	}
	return ret;
}

int M[1000][1000];

int main(){ _
	int n, m; cin >> n >> m;
	ii ans = rec(n, m, 0);
/*	for(int i=0; i<n;i++) for(int j=1; j<=n; j++){
		ii p = rec(n, i*n+j, 0);
//		cout << i*n+j << " -> " << p.f <<"  "<< p.s << endl;
		M[p.f][p.s] = i*n+j;
	}
	for(int j=n; j>=1; j--){ for(int i=1; i<=n; i++) 
		cout <<  M[i][j] << " ";
		cout << endl;
	}
*/	
	cout << ans.f << " " << ans.s << endl;
	
	
	exit(0);
}
