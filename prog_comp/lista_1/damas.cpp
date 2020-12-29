#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define MP make_pair
#define PB push_back

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

int n, m;

bool allow(int x, int y){
	if (x > n || x < 0) return false;
	if (y > m || y < 0) return false;
	return true;
}

int x_move[4] = {1, -1, -1,  1};
int y_move[4] = {1,  1, -1, -1};

int walk(int x, int y, vector <vector <int>> aux){
	int mx = 0;

	for (int i = 0; i < 4; i++){
		int ox = x + x_move[i];
		int oy = y + y_move[i];
		int nx = x + 2*x_move[i];
		int ny = y + 2*y_move[i];

		if (allow(ox, oy) && allow(nx, ny)){
			if (aux[ox][oy] == 2 && aux[nx][ny] == 0){
				aux[ox][oy] = -1;
				mx = max(1 + walk(nx, ny, aux), mx);
				aux[ox][oy] = 2;
			}
		}
	}

	return mx;
}

int main(){	

	while (true){
		vector <vector <int>> board(21);

		for (int i = 0; i < 21; i++)
			board[i].resize(21);

		map <int, pair <int, int>> mine;

		cin >> n >> m;

		if (n == 0 && m == 0) exit(0);

		bool flag = 0;
		int k = 1;
		cout << "HM" << endl;

		for (int i = 0; i < n; i++){
			for(int j=i%2; j<m; j+=2){
				cout << "HM" <<i*j << endl;
				cin >> board[i][j];
			}
		}
		cout << "HM" << endl;

		int ans = 0;
		for (int i = 0; i < n; i++){
			for(int j=i%2; j<m; j+=2){
				if(board[i][j]==1){
					cout << i <<"  "<< j << endl;
					vector <vector <int>> aux = board;
					aux[i][j] = 0;
					ans = max(ans, walk(i, j, aux));
				}
			}
		}


		cout << ans << endl;
	}
	
	return 0;
}
