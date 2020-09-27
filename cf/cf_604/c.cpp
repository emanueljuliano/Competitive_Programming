#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	int t;
	cin >> t;
	for(int k=0; k<t; k++){
		int n;
		cin >> n;
		int a;
		vector <int> v;
		for(int i=0; i<n; i++){
			cin >> a;
			v.pb(a);
		}


		int g, s, b;
		g = 0;s = 0;b = 0;
		for(int i=0; i<n/2; i++){
			if(v[i]!= v[i+1]){
				if(g>=1){
					if(s>g){
						b = i-g-s+1;
					}
					else
						s = i-g+1;
				}
				else
					g = i+1;
			}
		}

		if(g>= s or g>= b){
			cout << "0 0 0" << endl;
		}
		else if(s==0 or g==0 or b==0){
			cout << "0 0 0" << endl;
		}
		else
			cout << g << " " << s << " " << b << endl;
	}


	exit(0);
}
