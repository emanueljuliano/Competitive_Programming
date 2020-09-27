#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll a, b, c;
bool val(ll x, int flag){
	if(flag==1){
		x+=a;
		if(x==b or x==c) return false;
		if((abs(x-b) == abs(b-c) or abs(x-c)==abs(b-c)) and x>b and x>c) return false;
		return true;
	}
	else{
		x+=b;
		if(x==a or x==c) return false;
		if((abs(x-a) == abs(a-c) or abs(x-c)==abs(a-c)) and x>a and x>c) return false;
		return true;	
	}
}

int main(){ _
	cin >> a >> b >> c;
	if(a==b or b==c or a==c){
		cout << "First" << endl;
		int resp; cin >> resp;
	//	if(resp==0) exit(0);
	//	if(a==b) cout << "3" << endl;
	//	if(a==c) cout << "2" << endl;
	//	if(b==c) cout << "1" << endl;
	//	cin>> resp;
	}	
	else{
		int ant = -1;
		cout << "Second" << endl;
		for(int k=0; k<1001; k++){
			ll x=abs(a-b), y = abs(a-c), z=abs(b-c);
			int r; cin >> r;
			if(r==0 or r==-1) exit(0);
			if(ant!=1 and val(r, 1)){
				a+= r;
				cout << "1" << endl;
			}
			else if(ant!=2 and val(r, 2)){
				b+= r;
				cout << "2" << endl;
			}
			else{
				c+=r;
				cout << "3" << endl;
			}
		}
	}




	exit(0);
}
