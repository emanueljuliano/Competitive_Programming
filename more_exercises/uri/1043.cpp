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
	double a, b, c; cin >> a >> b >> c;
	cout << setprecision(1) << fixed;
	if(a+b<=c or a+c<=b or c+b<=a){
		cout << "Area = " <<  (a+b)*c/2 << endl;
	}
	else{
		cout << "Perimetro = " << a+b+c << endl;
	}
	
	
	
	exit(0);
}
