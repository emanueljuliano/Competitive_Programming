#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	int q;
	cin >> q;
	for(int i=0; i<q; i++){
		int a, b, c;
		cin >> a >> b >> c;
		if(a>b) swap(a, b);
		if(b>c) swap(b, c);
		if(a>b) swap(a, b);
		if(c-a>=2){
			c--; a++;
			if(2*b > c+a) b--;
			else if(2*b < c+a) b++;
		}
		else{
			if(c>b) b++, a++;
			else if(a<b) b--, c--;
		}
		cout << b-a + c-a + c-b << endl;		
	}	


	exit(0);
}
