#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
 
typedef __int128 ll;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll gcd(ll a, ll b) {
	if(a<0) a = -a;
	if(b<0) b = -b;
	return !b ? a : gcd(b, a%b);
}

ll lcm(ll a, ll b) {
	return a/gcd(a, b)*b;
}

struct fra {
    ll a,b;
    fra(ll a_ = 1, ll b_ = 1) : a(a_), b(b_){
        ll x = gcd(a, b);
        a /= x;
        b /= x;
    }
 
    fra operator + (const fra& B) const{
        fra A = *this; 
        
        ll d = lcm(A.b, B.b);
        ll n = A.a * d/A.b + B.a * d/B.b;
 
        return fra(n, d);
    }
 
    fra operator - (const fra& B) const{
        fra A = *this;
        
        ll d = lcm(A.b, B.b);
        ll n = A.a * d/A.b - B.a * d/B.b;
 
        return fra(n, d);
    }
 
    void print(){
		ll x = gcd(a, b);
        a /= x;
        b /= x;
		long long a1 = a;
		long long b1 = b;
		cout << a1 << "/" << b1 << endl;
    }
 
};
 
string S;
 
fra single(int l, int r) {
	if(l>=r) return fra(0, 1);
    int barra = -1;
    for(int i = l; i <= r; i++){
		assert(S[i]!='+' and S[i]!='-');
		if(S[i] == '/'){
			barra = i;
        }
    }
 
    ll n = stoll(S.substr(l , barra - l));
    ll d = stoll(S.substr(barra + 1, r - barra));
    return fra(n, d);
}

const int MAX = 2e5+10;
int f[MAX];

fra parse(int l, int r){
	if(l>=r) return fra(0, 1);
	if(f[l]==r) return parse(l+1, r-1);
	if(f[l]) {
		int plus = S[f[l]+1]=='+';
		if(plus) return parse(l, f[l]) + parse(f[l]+2, r);
		else return parse(l, f[l]) - parse(f[l]+2, r);
	}
	int sign = -1, plus=1;

	fra at(0, 1);
	int it = l;
	for(int i=l; i<=r; i++) {
		if(S[i]=='+' or S[i]=='-'){
			if(plus) at = at + parse(it, i-1);
			else at = at - parse(it, i-1);
			sign = i; plus = S[i]=='+';
			it = i+1;
		}
		else if(S[i]=='('){
			if(plus) at =  at + parse(i, f[i]);
			else at = at - parse(i, f[i]);
			it = f[i]+2;
			i = f[i];
		}
	}

	if(sign==-1) return single(l, r);
	if(it<r){
		if(plus) at = at + parse(it, r);
		else at = at - parse(it, r);
	}
	return at;
}
 
int main() { 
 
    while (cin >> S) {
		vector<int> stk;
        for (int i=0;i <S.size(); i++) {
			f[i] = 0;
			if(S[i]=='(') stk.push_back(i);
			else if(S[i]==')') f[stk.back()]=i, stk.pop_back();
		}
		parse(0, int(S.size()) - 1).print();
 	}
    exit(0);
}
