#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"
#define ss second
#define ff first

typedef pair<int, int> pii;
typedef long long ll;


int main(){ _
	int t, n;
	cin >> t;
	for(int j=0; j<t; j++){
		cin >> n;
		vector <int> a;
		vector <int> b;
		int aux;
		for(int i=0; i<n; i++){
			cin >> aux;
			a.push_back(aux);
		}
		int dif = 0;
		bool flag = false;
		for(int i=0; i<n; i++){
			cin >> aux;
			if(aux!=a[i] and dif==0)
				dif = a[i]-aux;
			else if(aux!=a[i] and a[i]-aux != dif)
				flag = true;	
			if(dif>0)
				flag = true;
			if(aux==a[i] and dif!=0)
				dif = -1000000;
			
		}

		if(flag)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
		


	}



	exit(0);
}
