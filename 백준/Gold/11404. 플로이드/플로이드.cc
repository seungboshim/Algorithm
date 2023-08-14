#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int n, m;
int v[101][101];
const int INF = 1e9;

int main() {
	cin >> n;
	cin >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
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
		v[a][b] = min(v[a][b], c);
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				v[i][j] = min(v[i][j], v[i][k] + v[k][j]);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (v[i][j] == INF)
				cout << 0 << " ";
			else
				cout << v[i][j] << " ";
		}
		cout << endl;
	}

	return 0;

}