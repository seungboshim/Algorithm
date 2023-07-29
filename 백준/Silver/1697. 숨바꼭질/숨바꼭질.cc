#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, K;
queue<pair<int, int>> q;
vector<bool> visited(100001, false);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	q.push(make_pair(N, 0));
	int minVal = 100001;

	while (!q.empty()) {
		int curr = q.front().first;
		int cnt = q.front().second;
		q.pop();
		visited[curr] = true;

		if (curr == K) {
			cout << cnt << "\n";
			return 0;
		}

		int dx[3] = { 1, -1, curr };
		for (int i = 0; i < 3; i++)
		{
			int next = curr + dx[i];
			if (next < 0 || next > 100000) continue;
			if (visited[next] == false) {
				q.push(make_pair(next, cnt + 1));
			}
		}

		minVal = min(minVal, cnt);
	}
	return 0;
}