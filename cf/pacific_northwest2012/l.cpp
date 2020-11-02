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


int main(){ _
		

	vector<char> vo = {'a', 'i', 'y', 'e', 'o', 'u'};
	vector<char> co = {'b', 'k', 'x', 'z', 'n', 'h', 'd', 'c', 'w',
		'g', 'p', 'v', 'j', 'q', 't', 's', 'r', 'l', 'm', 'f'};
	
	map<char, char> m;
	for(int i=0;i <6; i++)
		m[vo[i]] = vo[(i+3)%6];
	for(int i=0;i <20; i++)
		m[co[i]] = co[(i+10)%20];
	
	string aux;
	
	while(getline(cin, aux)){
		for(char c : aux){
			if(c<='Z' and c>='A'){
				c = c-'A'+'a';
				char nc = m[c] - 'a' + 'A';
				cout << nc;
				continue;
			}
			if(m.count(c))
				cout << m[c];
			else cout << c;
		}
		cout << endl;
	}
	exit(0);
}
