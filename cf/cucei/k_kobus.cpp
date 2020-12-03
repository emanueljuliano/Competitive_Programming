// Código da USP, mas fazendo alguns testes
#include <bits/stdc++.h>
using namespace std;

int qtot = 0;

int query(int a, int b, int c) {
  	//assert(++qtot < 7777);
    //if(++qtot>=7777) while(true){}
	a++; b++; c++;
    printf("? %d %d %d\n", a, b, c);
    fflush(stdout);
    int k;
    scanf("%d", &k);
    return k - 1;
}

int find(vector<int>& v, int p, int mn) {
    vector<int> left, right;
    for (int i = 1; i < v.size(); i++) {
        if (query(mn, v[0], v[i]) == v[0]) right.push_back(v[i]);
        else left.push_back(v[i]);
    }
    if (left.size() > p) return find(left, p, mn);
    if (left.size() < p) return find(right, p - int(left.size()) - 1, mn);
    return v[0];
}

int main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int n; scanf("%d", &n);

    int mn = 0, mx = 1;
    for (int i = 2; i < n; i++) {
        int k = query(mn, i, mx);
        if (k == mn) mn = i;
        if (k == mx) mx = i;
    }

    vector<int> v;
    for (int i = 0; i < n; i++) {
        if (i != mn && i != mx) v.push_back(i);
    }
    shuffle(v.begin(), v.end(), rng);
    int k = find(v, (n - 2) / 2, mn);
    printf("! %d\n", k + 1);
    fflush(stdout);
}

