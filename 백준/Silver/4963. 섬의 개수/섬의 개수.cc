#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// vector<vector<int>> map;
// vector<vector<bool>> visited;
int map[51][51];
bool visited[51][51];
queue<pair<int, int>> q;
int cnt = 0;

int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

// -1,-1   0,-1    1,-1
// -1,0    0,0     1,0
// -1,1    0,1     1,1


void bfs(int i, int j, int w, int h) {
    q.push({i, j});
    visited[i][j] = true;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx<0 || nx>=h || ny<0 || ny>=w || visited[nx][ny] || map[nx][ny]==0) {
                continue;
            } else {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    cnt++;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int w, h;
    while (cin >> w >> h) {
        cnt = 0;

        if (w==0 && h==0) {
            break;
        }

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> map[i][j];
                visited[i][j] = false;
            }
        }

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (!visited[i][j] && map[i][j]==1) {
                    bfs(i, j, w, h);
                }
            }
        }

        cout << cnt << endl;
    }
}