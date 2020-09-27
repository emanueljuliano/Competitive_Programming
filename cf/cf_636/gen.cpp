#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


int main(int argc, char *argv[]){ 
	srand(atoi(argv[1]));	
	int a = 4;
	cout << 1 << endl;
	cout << 6 << " " << 21 << endl;
	for(int i=0;i <6; i++){
		cout << rand() % 21 + 1<< " ";
	}
	cout << endl;
	
	
	exit(0);
} 
