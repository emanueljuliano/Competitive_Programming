#include <bits/stdc++.h>

using namespace std;

//#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


int main(){
	int t; cin>> t;
	while(t--){
		int b; cin >> b;
			vector<int> v;
			int at;
			cout << 1 << endl;
			cin >> at;
			cout << 1 << endl;
			cin >> at;

			for(int i=1; i<=4; i++){
				cout << s << endl;
				cin >> at;
				v.pb(at);
			}

			int ig = 0;
			int dif = 0;
			for(int i=0;i <10; i++){
				if(v[i]==v[9-i])ig++;
				else dif++;
			}
			if(ig==0 or dif==0){
				cout << 1 << endl;
				cin >> at;
				if(at!=v[0])
					for(int i=0;i <10; i++)
						v[i] = !v[i];
			}
			else{
				bool sw, ch, swch;
				sw = false; ch = false; swch = false;
				for(int i=0;i <b; i++){
					if(v[i] != v[9-i]){
						cout  << i+1 << endl;
						cin >> at;
						if(at!=v[i]) sw = true, ch = true;
						else swch = true;
						break;
					}
				}
				for(int i=0;i <b; i++){
					if(v[i] == v[9-i]){
						cout  << i+1 << endl;
						cin >> at;
						if(at!=v[i]) sw &= false, ch &= true;
						else swch &= false, ch &= false;
						break;
					}
				}
				if(sw) reverse(v.begin(), v.end());
				else if(ch) for(int i=0;i <b; i++) v[i] = !v[i];
				else if(swch){reverse(v.begin(), v.end()); for(int i=0;i <b; i++) v[i] = !v[i];}

			}

			for(int i=0;i <10; i++){
				cout << v[i];
			}
			cout << endl;
			char ans;
			cin >> ans;
	}
	
	
	
	exit(0);
}

