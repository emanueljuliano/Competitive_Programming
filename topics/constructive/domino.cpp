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
	int n; cin >> n;
	
	if(n%2==1){
		cout << 'a';
		string s1 = "bc";
		for(int i=1;i <n; i+=2){
			cout << s1[i/2%2] << s1[i/2%2];
		}
		cout << endl;
		cout << 'a';
		string s2 = "de";
		for(int i=1;i <n; i+=2){
			cout << s2[i/2%2] << s2[i/2%2];
		}
		cout << endl;
		string s3 = "xy";
		for(int i=0;i <n-1; i+=2){
			cout << s3[i/2%2] << s3[i/2%2];
		}
		cout << "z" << endl;
		string s4 = "uv";
		for(int i=0;i <n-1; i+=2){
			cout << s4[i/2%2] << s4[i/2%2];
		}
		cout << "z" << endl;
	}
	else{
		cout << 'a';
		string s1 = "bc";
		for(int i=1;i <n-1; i+=2){
			cout << s1[i/2%2] << s1[i/2%2];
		}
		cout << 'f' << endl;
		cout << 'a';
		string s2 = "de";
		for(int i=1;i <n-1; i+=2){
			cout << s2[i/2%2] << s2[i/2%2];
		}
		cout << 'f' << endl;
		string s3 = "xy";
		for(int i=0;i <n; i+=2){
			cout << s3[i/2%2] << s3[i/2%2];
		}
		cout << endl;
		string s4 = "uv";
		for(int i=0;i <n; i+=2){
			cout << s4[i/2%2] << s4[i/2%2];
		}
		cout << endl;	
	}
	
	exit(0);
}
