#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	
	int n;
	cin >> n;
	for(int k=0; k<n; k++){
		string a, b;
		cin >> a >> b;
		bool flag = false;
		int m_a = 0;
		int at = 0;
		// menor string de a
		for(int i=0; i<a.size(); i++){
			if(a[i]<=a[m_a]) m_a = i;
		}
		if(a[m_a] < b[0]){
			swap(a[m_a], a[0]);
			cout << a << endl;
			continue;
		}
		for(int i=0; i<a.size() && i<b.size() && i<m_a; i++){
			if(a[m_a]<b[i]){swap(a[i], a[m_a]); cout << a << endl; flag=true; break;}
			if(a[i]>b[i]) break;
		} 
		if(flag) continue;
		for(int i=0; i<a.size() && i<b.size(); i++){
			if(a[m_a]==b[i] and a[i]!=b[i] and i<m_a){
				swap(a[i], a[m_a]);
				for(int j=0; j<a.size() && j<b.size(); j++){
					if(a[j]<b[j]){cout << a << endl; flag = true; break;}
					if(a[j]>b[j]) break;
				}
				if(flag) break;
				for(int j=0; j<a.size() && j<b.size(); j++){
				if(a[j]==b[j]){		
						if(a[j]==a[at]) at++; 
					}
					else break;
				}
				if(at==a.size() and a!=b and a[0]==b[0]){ cout << a << endl; flag=true;}
			}
			if(a[i]>b[i]) break;
		}
		

		if(flag) continue;
		// olha se a é menor
		for(int i=0; i<a.size() && i<b.size(); i++){
			if(a[i]<b[i]){cout << a << endl; flag = true; break;}
			if(a[i]>b[i]) break;
		}
		if(flag) continue;
		at=0;
		// olha se a é sufixo e até onde são iguais
		for(int i=0; i<a.size() && i<b.size(); i++){
			if(a[i]==b[i]){		
					if(a[i]>=a[at]) at++; 
			}
			else break;
		}
		if(flag) continue;
		if(at==a.size() and a!=b and a[0]==b[0]){ cout << a << endl; continue;}
		if(at==b.size() and a!=b and a[0]==b[0]){ cout << "---" << endl; continue;}
		
		cout << "---" << endl;
		continue;		


		//são diferentes em 0?
		bool d0 = a[0]>b[0];
		int iguais = 0;
		if(d0){
			for(int i=0; i<a.size(); i++){
				if(a[i]<b[0]) {swap(a[iguais], a[0]); swap(a[i], a[0]); cout << a << endl; flag=true; break;}
				if(a[i]==b[0]) {swap(a[iguais], a[0]); swap(a[i], a[0]); iguais=i;}
			}
		}
		if(flag) continue;
			//a é menor?
		for(int i=0; i<a.size() && i<b.size(); i++){
			if(a[i]<b[i]){cout << a << endl; flag = true; break;}
			if(a[i]>b[i]) break;
		}
		if(flag) continue;
		int at2=0;

		cout << a << endl;
		// a é sufixo?
		for(int i=0; (i<a.size() && i<b.size()); i++){
			if(a[i]==b[i]) at2++;	
			else break;
		}		
		if(at2==a.size() and a!=b and a[0]==b[0]){ cout << a << endl; continue;}
		if(at2==b.size() and a!=b and a[0]==b[0]){ cout << "---" << endl; continue;}
	
		//sao diferentes em at+1
		iguais = at+1;
		//cout << b[at+1] << endl;
		for(int i=at+1; i<a.size(); i++){
			if(a[i]<b[at+1]) {swap(a[at+1], a[iguais]); swap(a[i], a[at+1]); cout << a << endl; flag=true; break;}
			if(a[i]==b[at+1]) {swap(a[iguais], a[at+1]); swap(a[i], a[at+1]); iguais=i;} 
		}
		if(flag) continue;
		for(int i=0; (i<a.size() && i<b.size()); i++){
			if(a[i]<b[i]){cout << a << endl; flag = true; break;}
			if(a[i]>b[i]) break;
		}
		if(flag) continue;
		// a é sufixo?
		at2=0;
		for(int i=0; (i<a.size() && i<b.size()); i++){
			if(a[i]==b[i]){ ++at2;}	
			else break;
		}	
		if(at2==a.size() and a!=b){ cout << a << endl; continue;}
		if(at2==b.size() and a!=b){ cout << "---" << endl; continue;}
		
		cout << "---" << endl;
	
	}

	exit(0);
}
