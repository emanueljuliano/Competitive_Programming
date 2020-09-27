// Show show provar o pq de bruteforce funcionar
// Tentar fazer com seg dps
// https://codeforces.com/contest/1073/problem/D

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX = 200200;
ll a[MAX];

int main(){ ios_base::sync_with_stdio(0);cin.tie(0);
	ll n, p;
	cin >> n >> p;
	ll soma = 0;
	for(int i=1; i<=n; i++){
		cin>> a[i];
		soma += a[i];
	}

	ll count=0;
	ll num = n;
	while(soma>0){
		if(soma<=p){
			count += (p/soma)*num;
			p = p - (p/soma)*soma;
		}
		else{
			for(int i=1; i<=n; i++){
				if(a[i]==0) continue;
				if(a[i]<=p){
					p-=a[i];
					count++;
				}
				else{
					soma -= a[i];
					num--;
					a[i]=0;
				}
			}
		}
	}
	cout << count << endl;
}
