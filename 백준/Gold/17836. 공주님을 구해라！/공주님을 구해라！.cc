#include <iostream>
#include <queue>
using namespace std;

int N, M, T;
int map[102][102];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int main() {
    cin >> N >> M >> T;

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            cin >> map[i][j];

    struct P { int x, y, t, sword; };
    bool visited[102][102][2] = { false };
    queue<P> q;
    q.push({ 1, 1, 0, false }); // (1,1) 에서 지나온 발판 0, sword false
    visited[1][1][0] = true; // (1,1)을 검 없는 상태로 방문

    while (!q.empty()) {
        P p = q.front(); q.pop();
        if (p.t > T) continue; // T보다 오래 걸림
        if (p.x == N && p.y == M) { // 도착
            cout << p.t << endl;
            return 0;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];
            int nt = p.t + 1;
            int ns = p.sword;
            if (nx < 1 || nx > N || ny < 1 || ny > M) continue;
            if (visited[nx][ny][ns]) continue;

            if (map[nx][ny] == 1 && !p.sword) continue;

            if (map[nx][ny] == 2 && !p.sword) { // 검을 찾은 경우
                ns = 1; // 검을 획득
            }
            q.push({ nx, ny, nt, ns });
            visited[nx][ny][ns] = true;
        }
    }

    cout << "Fail" << endl;

    return 0;
}
