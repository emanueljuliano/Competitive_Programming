#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


int main(){ _
	double a, b, c, d;
	cin >> a >> b >> c >> d;
	double media =  (2*a+3*b+4*c+d)/10.0;
	cout << setprecision(1) << fixed;
	cout << "Media: " << media << endl;
	if(media < 5) cout << "Aluno reprovado." << endl;
	else if(media <7){
		cout << "Aluno em exame." << endl;
		double e; cin >> e;
		cout << "Nota do exame: " << e << endl;
		media = (media + e)/2;
		if(media<5) cout << "Aluno reprovado." << endl;
		else cout << "Aluno aprovado." << endl << "Media final: " << media << endl;
	}
	else{
		cout << "Aluno aprovado." << endl;
	}
	
	
	
	exit(0);
}
