#include <bits/stdc++.h>
#define s second
#define f first
#define pb push_back
#define endl '\n'
using namespace std;


typedef long long ll;
typedef pair<int,int> pii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int N,M;

vector<vector<char>> A,B;
vector<vector<int>> X,Y,D;

vector<pii> mv = {{1,0}, {-1,0}, {0,1}, {0,-1}};

void BFS2(pii a, pii b, bool W){

	queue<pii> Q;
	Q.push(a);
	Q.push(b);

	if(W){
		X[a.f][a.s] = 0;
		X[b.f][b.s] = 0;
	}
	else{
		Y[a.f][a.s] = 0;
		Y[b.f][b.s] = 0;
	}	

	while(Q.size()){
		pii v = Q.front();	
		Q.pop();
		for(auto x : mv){
			pii u = {x.f + v.f, x.s + v.s};

			if(u.f < 0 || u.f >= N) continue;
			if(u.s < 0 || u.f >= M) continue;
			if(W){
				if(X[u.f][u.s] != INF) continue;
				if(A[u.f][u.s] == '#') continue;
				X[u.f][u.s] = X[v.f][v.s] + 1;
				Q.push(u);
			}
			else{
				if(Y[u.f][u.s] != INF) continue;
				if(B[u.f][u.s] == '#') continue;
				Y[u.f][u.s] = Y[v.f][v.s] + 1;
				Q.push(u);
			}
		}
	}

}

bool can(pii from, pii to){

	queue<pii> Q;
	Q.push(from);

	while(Q.size()){
		assert(Q.size() <= N*M);
		pii v = Q.front();
		Q.pop();

		if(v == to) return 1;

		D[v.f][v.s] = 0;		

		for(auto x : mv){
			pii u = {x.f + v.f, x.s + v.s};

			if(u.f < 0 || u.f >= N) continue;
			if(u.s < 0 || u.s >= M) continue;
			if(!D[u.f][u.s]) continue;
			
			D[u.f][u.s] = 0;		

			Q.push(u);
		}

	}	

	return 0;
}

void print(vector<vector<int>> T){
	cout << endl;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cout << (T[i][j] == INF ? "x" : to_string(T[i][j])) << " \n"[j == M-1];
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	A.assign(N, vector<char>(M));
	B.assign(N, vector<char>(M));

	X.assign(N, vector<int>(M,INF));
	Y.assign(N, vector<int>(M,INF));
	D.assign(N, vector<int>(M,0));


	for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) cin >> A[i][j];
	for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) cin >> B[i][j];


	BFS2({0,0}, {N-1,M-1}, 1);
	BFS2({0,0}, {N-1,M-1}, 0);

	//	print(X);
	//	print(Y);

	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(X[i][j] == INF) continue;
			D[i][j] = (X[i][j] == Y[i][j]);
		}
	}

	//	print(D);

	cout << (can({0,0}, {N-1,M-1}) ? "YES" : "NO") << endl;

	return 0;
}
