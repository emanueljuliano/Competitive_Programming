#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	int n;
	cin >> n;
	vector <int> v(200200, 0), w(200200, 0);
	vector<int> deu, rec;
	int zeros=0;
	set<int> visto; 
	for(int i=1; i<=n; i++){
		int a;
		cin >> a;
		v[i]=a;
		w[a]=i;
		if(a!=0)
		visto.insert(a);
	}

/*	for(int i=1; i<=n; i++){
		int a;
		if(v[i]!=0){
			a = v[i];
			if(v[a]==0 and !visto.count(i)){
				v[a] = i;
				visto.insert(i);
			}
		}
	}
*/
	int at=0;

	for(int i=1; i<=n; i++){
		if(v[i]==0) deu.pb(i);
		if(w[i]==0) rec.pb(i);
	}
	for(int i=1; i<deu.size(); i++){
	while(true){
		if(deu[i]!=rec[at] and !visto.count(rec[at])){
			w[rec[at]] = deu[i];
			v[deu[i]] = rec[at];
			visto.insert(rec[at]);
			break;
		}
		else{
			at = (at+1)%rec.size();
		}
	}
	}
	int cert=0;
	int oc = 0;
	for(int i=1; i<=n; i++){
		if(v[i]==0) cert=i;
		if(!visto.count(i))oc=i;
	}
	v[cert]=oc;
	for(int i=1; i<=n; i++)
		cout << v[i] << " ";
	cout << endl;
	exit(0);
}
