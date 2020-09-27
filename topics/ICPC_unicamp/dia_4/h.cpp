#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"
#define pb push_back

typedef long long ll;
double pd[1010][1010];
int n, x, y;

double rec(int menor, int maior){
	double &ans = pd[menor][maior];
	if(ans != -1.0) return ans;
	if(menor+maior+1 == y){
		if(menor == 0) return ans = 0.0;
		return 2.0*menor/double((maior + menor)*(maior + menor+1.0)); 
	}
	
	ans = 0.0;
	if(maior>0)
		ans += 2.0*double(maior / ((maior+menor)*(maior+menor+1.0))) 
			* rec(menor, maior-1);
//	cout << " maeu " << ans;
	if(maior>1)
		ans += double(maior*(maior-1.0) / ((maior+menor)*(maior+menor+1.0)))
			* rec(menor, maior-1);
//	cout << " mama " << ans;
	if(menor>1)
		ans +=  double(menor*(menor-1.0) / ((maior+menor)*(maior+menor+1.0)))
			* rec(menor-1, maior);
//	cout << " meme " << ans<< " mame ";
	if(menor>0 and maior>0)
		ans += 2.0*double(maior*menor/ ((maior+menor)*(maior+menor+1.0)))
			* rec(menor, maior-1);
	
//	cout << menor << " "<< maior << " " << ans <<endl;
	return ans;
}
int main(){// _
	while(cin >> n >> x >> y){
		for(int i=0; i<=n; i++)
			for(int j=0; j<=n; j++)
				pd[i][j] = -1.0;
		
		cout << setprecision(4) << fixed;	
		if(y==1 and x!=1) {cout << 0.0 << endl; continue;}
		else if(y==1 and x==1) {cout << 1.0 << endl; continue;}
		cout << rec(x-1, n-x) << endl;
	}
	exit(0);
}
