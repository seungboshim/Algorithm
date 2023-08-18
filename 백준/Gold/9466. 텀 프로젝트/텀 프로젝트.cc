#include <iostream>
#include <cstring>

using namespace std;

int T, n;
int student[100001];
int visited[100001];
int done[100001];

int dfs(int curr) {
	visited[curr] = true; // curr 방문
	int next = student[curr];
	int cycle = 0;

	if (visited[next] == false) {
		cycle = dfs(next);
	}
	else if (done[next] == false) {
		for (int i = next; i != curr; i = student[i])
		{
			cycle++;
		}
		cycle++;
	}
	done[curr] = true;
	return cycle;
}

int main() {
	cin >> T;
	while (T--) {
		cin >> n;
		for (int j = 1; j <= n; j++)
		{
			cin >> student[j];
		}

		// 초기화
		memset(visited, false, sizeof(visited));
		memset(done, false, sizeof(done));
		int ans = 0; // 팀에 속한 학생수

		for (int j = 1; j <= n; j++)
		{
			if (visited[j] == false) {
				ans += dfs(j);
			}
		}
		cout << n - ans << "\n";
	}
	return 0;
}