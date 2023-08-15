#include <iostream>
#include <vector>
using namespace std;

int n, m;
int v[101][101];
int P[101][101];
const int INF = 1e9;
int C[101][101];
vector<int> pathV;

void path(int q, int r, int& cnt) { 
	if (P[q][r] != 0) {
		path(q, P[q][r], cnt);
		pathV.push_back(P[q][r]);
		path(P[q][r], r, cnt);
		cnt++;
	}
	C[q][r] = cnt;
}

int main() {
	cin >> n;
	cin >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			P[i][j] = 0;
			if (i == j) {
				v[i][j] = 0;
			}
			else {
				v[i][j] = INF;
			}
		}
	}

	int a, b, c;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		v[a][b] = min(v[a][b], c); // 중복된 노선은 최소비용만 저장
	}

	for (int k = 1; k <= n; k++) 
	{
		for (int i = 1; i <= n; i++) 
		{
			for (int j = 1; j <= n; j++) 
			{
				if (v[i][j] > v[i][k] + v[k][j]) {
					v[i][j] = v[i][k] + v[k][j];
					P[i][j] = k;
				}
			}
		}
	}


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (v[i][j] == INF)
				cout << 0 << " ";
			else
				cout << v[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 1; i <= n ; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (v[i][j] != 0 && v[i][j] != INF) {
				int cnt = 2; // i, j도 count 추가
				path(i, j, cnt);

				cout << C[i][j] << " ";
				cout << i << " ";
				for (int node : pathV) {
					cout << node << " ";
				}
				cout << j << " ";
				pathV.clear();
			}
			else 
				cout << 0;

			cout << "\n";
		}
	}

	return 0;
}