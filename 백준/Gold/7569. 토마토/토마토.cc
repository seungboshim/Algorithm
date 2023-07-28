#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int N, M, H;
int tomato[100][100][100];
queue<tuple<int, int, int>> q;
int dx[6] = { 0, 1, 0, -1, 0, 0 };
int dy[6] = { -1, 0, 1, 0, 0, 0 }; // 시계방향 이동
int dz[6] = { 0, 0, 0, 0, -1, 1 }; // 위/아래 이동

void BFS();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N >> H;
	for (int h = 0; h < H; h++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cin >> tomato[i][j][h];

				if (tomato[i][j][h] == 1) {
					q.push(make_tuple(i, j, h));
					// 익은 토마토 좌표 저장
				}
			}
		}
	}
	BFS();

	int day = 0;
	for (int h = 0; h < H; h++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (tomato[i][j][h] == 0) {
					cout << -1 << "\n";
					return 0;
				}
				day = max(day, tomato[i][j][h]);
			}
		}
	}

	cout << day - 1 << "\n";
	return 0;
}

void BFS() {
	while (!q.empty()) {
		int currX = get<0>(q.front());
		int currY = get<1>(q.front());
		int currZ = get<2>(q.front());
		q.pop();

		for (int i = 0; i < 6; i++)
		{
			int newX = currX + dx[i];
			int newY = currY + dy[i];
			int newZ = currZ + dz[i];

			if (newX < 0 || newX >= N || newY < 0 || newY >= M || newZ < 0 || newZ >= H)
				continue;
			if (tomato[newX][newY][newZ] == 0) {
				tomato[newX][newY][newZ] = tomato[currX][currY][currZ] + 1;
				q.push(make_tuple(newX, newY, newZ));
			}
		}
	}
}