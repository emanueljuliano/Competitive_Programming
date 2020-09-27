#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);


int n, q;
char a, b, v[200200][2];

bool flow(char a, int jj, int ii,  char veio){
	if(jj==n-1 and ii==1){
		if(veio=='c' and a=='2'){
			return true;
		}
		else if(veio=='e' and a=='1'){return true;}
		else {return false;}
	}
	else if(jj==n-1 and ii==0 and a=='2' and v[jj][1]=='2'){return true;}
	else if(jj==n-1){ return false;}

	if(a=='1' and veio=='e') return flow(v[jj+1][ii], jj+1, ii, 'e');
	if(a=='2'){
		if(veio == 'e'){
			if(ii==0)
				return flow(v[jj][1], jj, 1, 'c' );
			if(ii==1)
				return flow(v[jj][0], jj, 0, 'b');
		}
		if(veio=='b'){
			return flow(v[jj+1][0], jj+1, 0, 'e');
		}
		if(veio=='c'){
			return flow(v[jj+1][1], jj+1, 1, 'e');
		}
	}
	return false;

}

int main(){ _
	cin >> q;
	for(int i=0; i<q; i++){
		cin >> n;
		for(int j=0; j<n; j++){
			cin >> v[j][0];
			if(v[j][0] =='2') v[j][0] = '1';
			if(v[j][0]=='3' or v[j][0]=='4' or v[j][0]=='5' or v[j][0]=='6') v[j][0] = '2';
		}
		for(int j=0; j<n; j++){
			cin >> v[j][1];
			if(v[j][1] =='2') v[j][1] = '1';
			if(v[j][1]=='3' or v[j][1]=='4' or v[j][1]=='5' or v[j][1]=='6') v[j][1] = '2';
		}
		bool resp = flow(v[0][0], 0, 0, 'e');
		if(resp) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	
}
