#include <iostream>
#include <string>
#include <queue>
using namespace std;

int N, M;
int map[101][101];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		string line;
		cin >> line;
		for (int j = 1; j <= M; j++)
		{
			map[i][j] = line[j - 1] - '0';
		}
	}

	bool visited[101][101] = { false };
	queue<pair<pair<int, int>,int>> q;

	q.push({ { 1,1 },1 });
	visited[1][1] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int t = q.front().second;
		q.pop();

		if (x == N && y == M) {
			cout << t;
			return 0;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nt = t + 1;

			if (nx >= 1 && nx <= N && ny >= 1 && ny <= M 
				&& map[nx][ny] != 0 && visited[nx][ny] == false) 
			{
				q.push({ { nx, ny },nt });
				visited[nx][ny] = true;
			}
		}
	}
	return 0;
}