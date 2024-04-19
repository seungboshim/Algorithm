#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;

int map[501][501];
bool visited[501][501] = {false};
queue<pair<int, int>> q;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

vector<int> pictures;
int cnt = 0;

void bfs(int i, int j) {
    q.push({i, j});
    visited[i][j] = true;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int idx = 0; idx < 4; idx++)
        {
            int nx = cx + dx[idx];
            int ny = cy + dy[idx];
            if (nx>=0 && nx<n && ny>=0 && ny<m && !visited[nx][ny] && map[nx][ny]==1) {
                visited[nx][ny] = true;
                q.push({nx, ny});
                cnt++;
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && map[i][j]==1) {
                cnt = 1; // 초기화
                bfs(i, j);
                pictures.push_back(cnt);
            }
        }
    }

    cout << pictures.size() << "\n";

    int result = 0;
    for (auto &&i : pictures)
    {
        result = max(result, i);
    }
    cout << result << "\n";

    return 0;
    
}