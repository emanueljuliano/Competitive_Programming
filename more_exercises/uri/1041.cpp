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
	double x, y;
	cin >> x >> y;
	if(x==0 and y==0) cout << "Origem" << endl;
	if(x!=0 and y==0) cout << "Eixo X" << endl;;
	if(x==0 and y!=0) cout << "Eixo Y" << endl;;
	if(x>0 and y>0) cout << "Q1" << endl;;
	if(x>0 and y<0) cout << "Q4" << endl;;
	if(x<0 and y>0) cout << "Q2" << endl;;
	if(x<0 and y<0) cout << "Q3" << endl;;
	
	
	
	exit(0);
}
