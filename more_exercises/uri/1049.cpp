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
	string a, b, c; cin >> a >> b >> c;
	if(a=="vertebrado"){
		if(b=="ave"){
			if(c=="carnivoro"){
				cout <<"aguia" << endl;
			}
			else{
				cout <<"pomba" << endl;
			}
		}
		else{
			if(c=="onivoro"){
				cout <<"homem" << endl;
			}
			else{	
				cout <<"vaca" << endl;
			}
		}
	}
	else{
		if(b=="inseto"){
			if(c=="hematofago"){
				cout << "pulga" << endl;
			}
			else{
				cout << "lagarta" << endl;
			}
		}
		else{
			if(c=="hematofago"){
				cout << "sanguessuga" << endl;
			}
			else{
				cout << "minhoca" << endl;
			}
		}
	}
	
	
	
	exit(0);
}
