#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, K;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<bool> visited(100001, false);

int main() {
	cin >> N >> K;

	pq.push(make_pair(0, N));

	while (!pq.empty()) {
		int cnt = pq.top().first;
		int curr = pq.top().second;
		pq.pop();
		
		if (visited[curr]) continue;
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
				if (i == 2) {
					pq.push(make_pair(cnt, next));
				}
				else 
					pq.push(make_pair(cnt + 1, next));
			}
		}
	}
	return 0;
}