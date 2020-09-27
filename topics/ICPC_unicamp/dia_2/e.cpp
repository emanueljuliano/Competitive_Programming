#include <bits/stdc++.h>

using namespace std;

#define pb push_back

int main(){
		
	int n;
	cin >> n;
	vector<int> v;
	int a, b;
	a = b = 0;
	for(int i=0; i<n; i++){
		int s;
		cin >> s;
		for(int j=0; j<s; j++){
			int aux;
			cin >> aux;
			if(s%2==1 and j==(s/2))
				v.pb(aux);
			else{
				if(j<s/2)
					a+=aux;	
				else
					b+=aux;
			}
		}
	//cout << a << " " << b << endl;
	}
	sort(v.begin(), v.end(), greater<>());
	for(int i=0; i<v.size(); i++){
		if(i%2==0)
			a+=v[i];
		else
			b+=v[i];
	}
	cout << a << " " << b << endl;
}
