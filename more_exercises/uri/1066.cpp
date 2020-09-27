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
	int a=0, b=0, z=0;
	for(int i=0;i <5; i++){
		int x; cin >> x;
		if(x%2==0) a++;
		if(x>0) b++;
		if(x==0) z++;
	}	
	cout << a << " valor(es) par(es)" << endl;
	cout << 5-a << " valor(es) impar(es)" << endl;
	cout << b << " valor(es) positivo(s)" << endl;
	cout << 5-b-z << " valor(es) negativo(s)" << endl;
	
	
	exit(0);
}
