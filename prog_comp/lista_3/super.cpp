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
	int n;
	vector<int> primo((int)1e5+10, 1);
	primo[1] = 0, primo[0]=0;
	for(int i=2; i<primo.size(); i++) if(primo[i])
		for(int j=2*i; j<primo.size(); j+=i) primo[j] = 0;

	while(cin >> n){
		if(!primo[n]) cout << "Nada" << endl;
		else if(primo[n]){
			bool super = true;
			int at = 1;
			while(at<=n){
				if(!primo[n/at%10]) super = false;
				at*=10;
			}
			if(super) cout << "Super" << endl;
			else cout << "Primo" << endl;
		}

	}
	
	
	
	exit(0);
}
