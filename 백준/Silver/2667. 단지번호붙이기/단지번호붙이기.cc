#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
int map[26][26];
bool visited[26][26] = {false};
queue<pair<int,int>> Q; // bfs용 큐

int cnt = 0; // 현재 단지 크기 세기
vector<int> V; // 단지 크기 저장

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void bfs(int i, int j) {
    Q.push(make_pair(i, j));
    visited[i][j] = true;

    while(!Q.empty()) {
        int cx = Q.front().first;
        int cy = Q.front().second;

        Q.pop();

        for (int i=0; i<4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            // 지도 바깥, 이미 방문, 집 없음
            if (nx<0 || nx>=N || ny<0 || ny>=N || visited[nx][ny] || map[nx][ny]==0) 
                continue;

            // 집 있는 곳이면
            visited[nx][ny] = true; // 방문
            Q.push(make_pair(nx, ny)); // 큐 삽입
            cnt++; // 집 한개 추가

            // if (nx>=0 && nx<N && ny>=0 && ny<N && !visited[nx][ny] && map[nx][ny]==1) {
            //     visited[nx][ny] = true; // 방문
            //     Q.push(make_pair(nx, ny)); // 큐 삽입
            //     cnt++; // 집 한개 추가
            // }
        }
    }

}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < N; j++)
        {
            map[i][j] = temp[j] - '0'; // char '1' -> 정수 1
        }
    }
    
    // 모든 칸을 순회, 한 단지에 한번 bfs 수행
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (map[i][j] == 1 && !visited[i][j]) { // 1이면 bfs 시작
                cnt = 1;
                bfs(i, j);
                V.push_back(cnt);
            }
        }
    }

    sort(V.begin(), V.end());

    cout << V.size() << '\n';

    for (auto &&i : V)
    {
        cout << i << '\n';
    }
    
}