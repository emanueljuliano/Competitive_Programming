#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int main(int argc, char** argv){
	srand(atoi(argv[1]));
	int n = rand(), m = rand();
	cout << n << " " << m << endl;	
}
