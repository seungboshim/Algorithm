#include <iostream>
#include <queue>
using namespace std;

int N;
char map[101][101];
bool colorVisited[101][101] = {false};
bool nonColorVisited[101][101] = {false};

queue<pair<int,int>> colorQ;
queue<pair<int,int>> nonColorQ;

char curr; // 현재 칸
int colorCnt = 0;
int nonColorCnt = 0;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void colorBFS(int i, int j) {   
    colorQ.push({i, j});
    colorVisited[i][j] = true;

    while(!colorQ.empty()) {
        int cx = colorQ.front().first;
        int cy = colorQ.front().second;
        colorQ.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            // 범위를 벗어남, 이미 방문함, 색상이 다름 -> 탐색 X
            if (nx<0 || nx>=N || ny<0 || ny>=N || colorVisited[nx][ny] || map[cx][cy]!=map[nx][ny]) {
                continue;
            } else {
                colorVisited[nx][ny] = true;
                colorQ.push({nx,ny});
            }
        }
    }

    colorCnt++;
}

void nonColorBFS(int i, int j) {
    nonColorQ.push({i, j});
    nonColorVisited[i][j] = true;

    while(!nonColorQ.empty()) {
        int cx = nonColorQ.front().first;
        int cy = nonColorQ.front().second;
        nonColorQ.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            // 범위를 벗어남, 이미 방문함 -> 탐색 X
            if (nx<0 || nx>=N || ny<0 || ny>=N || nonColorVisited[nx][ny]) {
                continue;
            // 적록색맹 같은색 처리
            } else if (map[cx][cy]!=map[nx][ny]) {
                if (
                    (map[cx][cy] == 'R' && map[nx][ny] == 'G') ||
                    (map[cx][cy] == 'G' && map[nx][ny] == 'R')
                ) {
                    nonColorVisited[nx][ny] = true;
                    nonColorQ.push({nx,ny});
                } else {
                    continue;
                }
            } else {
                nonColorVisited[nx][ny] = true;
                nonColorQ.push({nx,ny});
            }
        }
    }

    nonColorCnt++;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            curr = map[i][j];
            if (!colorVisited[i][j]) {
                colorBFS(i, j);
            }
            if (!nonColorVisited[i][j]) {
                nonColorBFS(i, j);
            }
        }
    }
    cout << colorCnt << ' ' << nonColorCnt << endl;
    
    return 0;
}