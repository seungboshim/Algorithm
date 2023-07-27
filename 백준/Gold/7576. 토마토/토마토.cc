#include <iostream>
#include <queue>

using namespace std;

int M, N;
int tomato[1000][1000];
queue<pair<int, int>> q;
int dx[4] = { 0, 1, 0, -1 }; 
int dy[4] = { -1, 0, 1, 0 }; // 시계방향 이동

void BFS() {
	while (!q.empty()) {
		int currX = q.front().first; 
		int currY = q.front().second; 
		// 현재 좌표 : 익은 토마토
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextX = currX + dx[i];
			int nextY = currY + dy[i];
			if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M) continue;
			// 박스를 벗어난 좌표 예외처리
			if (tomato[nextX][nextY] == 0) {
				// 안익은 토마토면
				tomato[nextX][nextY] = tomato[currX][currY] + 1;
				q.push(make_pair(nextX, nextY));
			}
		}
	}
}

int main() {
	cin >> M >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> tomato[i][j];

			if (tomato[i][j] == 1) { // 익은 토마토 좌표 저장
				q.push(make_pair(i, j));
			}
		}
	}
	BFS();

	int day = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (tomato[i][j] == 0) {
				cout << -1 << "\n";
				return 0;
			}
			day = max(day, tomato[i][j]);
		}
	}
	cout << day - 1 << "\n";
	return 0;
}