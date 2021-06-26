#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int LIM = 100;
const int LIM2 = 1e9;

int main(int argc, char** argv) { _
    srand(atoi(argv[1]));
    int n = rand()%LIM+1;
    cout << n << endl;
    for (int i = 0; i < n; i++) {
        cout << rand()%LIM2 << " " << rand()%LIM2 << endl;
    }
    exit(0);
}
