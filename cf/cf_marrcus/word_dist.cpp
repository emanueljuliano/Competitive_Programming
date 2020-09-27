#include <bits/stdc++.h>

using namespace std;

#define MAXN 10000

int lev(string s, string t){
	int d[MAXN][MAXN];
	memset(d, 0, sizeof(d));

	for(int i=1; i<= s.size(); i++) d[i][0] = i;
	for(int i=1; i<=t.size(); i++) d[0][i] = i;
	
	int cost;
	for(int i=1; i<=s.size(); i++){
		for(int j=1; j<=t.size(); j++){
			if(s[i]==t[i]) cost = 0;
			else cost = 1;
			d[i][j] = min(min(d[i-1][j]+1, d[i][j-1]+1), d[i-1][j-1] + cost);
		}
	}
	return d[s.size()][t.size()];
}


int main(){
	cout << "Levenshtein algorith" << endl;
}
