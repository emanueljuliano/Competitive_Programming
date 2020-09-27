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
	vector<int> w(n), ans(n);
	int x1=1, x2=1, y1=1, y2=1;
	int at = 0; x1++;
	for(int i=0;i <n; i++){
		int a, b; cin >> a >> b;
		w[i] = at;
		if(i%2==0){
			if(at==0 and b==1) y1++;
			else if(at==2 and b==1) y2++;
			else if(at==0 and b==-1) y2++;
			else if(at==2 and b==-1) y1++;
		}
		else{
			if(at%4==1 and b==1) x1++;
			else if(at==3 and b==1) x2++;
			else if(at==1 and b==-1) x2++;
			else if(at==3 and b==-1) x1++;
		}
		at+=b;
		at+=4;
		at%=4;
	}
	
	ans[n-1]=1;
	if(n>1)ans[n-2]=1;
	int x = 1;
	for(int i=n-3-!(n%2); i>=0; i-=2){
		if(w[i]==w[i+2]) x++, ans[i]=1;
		else ++x, ans[i]=x;
	}
	int y = 1;
	for(int i=n-3-(n%2); i>=0; i-=2){
		if(w[i]==w[i+2]) y++, ans[i]=1;
		else ++y, ans[i]=y;
	}
	
	for(auto k : ans) cout << k << " " ;
	cout << endl;
	
	exit(0);
}
