#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	int n;
	cin >> n;
	vector <int> v;
	int ans=0, aux=0, zeros=0;
	int pa=n/2, im=n/2;
	if(n%2!=0) im++;
	
	for(int i=0; i<n; i++){
		int a;
		cin >> a;
		if(i!=0 and a!=0 and aux!=0){
			if((aux+a)%2!=0)ans++;
		}
		if(a!=0 and a%2==0)pa--;
		else if (a!=0) im--;
		v.pb(a);
		aux = a;
	}

	vector<int> par, imp, tant;
	if(n==1){
		cout << 0 << endl;
		exit(0);
	}
	int at=-1;
	for(int i=0; i<n; i++){
		if(at==-1 and v[i]!=0) at=v[i];
		else if(at%2==0 and v[i]!=0 and v[i]%2==0)
			par.pb(zeros);
		else if(at%2!=0 and v[i]!=0 and v[i]%2!=0)
			imp.pb(zeros);
		else if(at%2==0 and v[i]!=0 and v[i]%2!=0)
			tant.pb(zeros);
		else if(at%2!=0 and v[i]!=0 and v[i]%2==0)
			tant.pb(zeros);

		if(v[i]==0) zeros++;
		else zeros=0;
		
		if(at!=-1 and v[i]!=0) at=v[i];
	}
	if(zeros==n){cout << 1 << endl; exit(0);}
//	cout << tant.size() << " " << par.size() << " " << imp.size() << endl;
//	cout << ans <<" " << pa << " "<< im << endl;
	sort(par.begin(), par.end());
	sort(imp.begin(), imp.end());
	
	//trata 0 no começo e fim
	int aux1=0, par1=0, par2=0;
	for(int i=0; i<v.size(); i++){
		if(v[i]!=0) {par1=v[i]%2;break;}
		aux1++;
	}
	int aux2=0;
	for(int i=v.size()-1; i>=0; i--){
		if(v[i]!=0) {par2=v[i]%2;break;}
		aux2++;
	}
	if(aux1>aux2){ swap(aux1, aux2); swap(par1, par2);}
	for(int l=0; l<2; l++){
	if(aux1>0){
//		cout << "OI " << aux1 <<  endl;
		if(par1==0){
			int soma=0;
			bool flag=true;
			for(int i=0; i<par.size(); i++){
				if(soma+par[i]>pa and soma+aux1<=pa){
					pa-=aux1;
					flag=false;
					break;
				}
				else if(soma+par[i]+aux1>pa){
					tant.pb(aux1);
					flag=false;
					break;
				}
				
				soma+=par[i];
			}
			if(flag){
				if(soma+aux1>pa) tant.pb(aux1);
				else pa-=aux1;
			}
		}
		if(par1!=0){
			int soma=0;
			bool flag=true;
//			cout << "UE" << endl;
			for(int i=0; i<imp.size(); i++){
				if(soma+aux1<=im and soma+imp[i]>im){
//					cout << 1 << endl;
					im-=aux1;
					flag=false;
					break;
				}
				else if(soma+imp[i]+aux1>im){
//					cout << 3 << endl;
					tant.pb(aux1);
					flag=false;
					break;
				}
				soma+=imp[i];
			}
			if(flag){
//				cout << 4 << endl;
				if(soma+aux1>im) tant.pb(aux1);
				else im-=aux1;
			}
		}
	}
	aux1 = aux2;
	par1 = par2;
	}
//	cout << tant.size() << endl;
//	cout << ans <<" " << pa << " "<< im << endl;
	//faz os role
	sort(par.begin(), par.end());
	sort(imp.begin(), imp.end());
	
	for(int i=0; i<par.size(); i++){
		if(par[i]==0) continue;
		if(pa>=par[i])
			pa-=par[i];
		else if(im>=par[i]){
			im -= par[i];
			ans+=2;
		}
		else{
			im+=pa;
			im -= par[i];
			pa=0;
			ans+=2;
		}
	}
	for(int i=0; i<imp.size(); i++){
		if(imp[i]==0) continue;
		if(im>=imp[i])
			im-=imp[i];
		else if(pa>=imp[i]){
			pa -= imp[i];
			ans+=2;
		}
		else{
			pa+=im;
			pa -= imp[i];
			im=0;
			ans+=2;
		}
	}
//	cout << ans << endl;
	for(int i=0; i<tant.size(); i++){
		if(tant[i]!=0){
			ans++;
			if(pa>=tant[i]) pa-=tant[i];
			else if(im>=tant[i]) im-=tant[i];
			else if(im+pa>=tant[i]) im+=pa, im-=tant[i], pa=0;
			else ans--;
		}
	}


	cout << ans << endl;
	exit(0);
}
