#include <bits/stdc++.h>
#define f first
#define s second
#define INF 0x3f3f3f3f
#define EPS 1e-9
using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); 
	int t;
	cin >> t;
	while(t--){
		string str;
		int cur = 0, best = INF;
		cin >> str;
		for(int i = 1; i < str.size(); i++){
			char ch = str[i];
			int prev = i - 1, next = i + 1;
			while(next < str.size() && str[next] == ch) next++;
			if(next < str.size() && str[prev] != str[next] && str[prev] != str[i])
				best = min(best, next - prev + 1);
			i = next - 1;
		}
		if(best == INF) cout << 0 << endl;
		else cout << best << endl;
	}


	return 0;
}
