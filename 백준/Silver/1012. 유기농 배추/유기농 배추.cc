#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> map;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void dfs(int x, int y) {

    map[x][y] = 0;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < map.size() && ny >= 0 && ny < map[0].size() && map[nx][ny] == 1) {
            dfs(nx, ny);
        } 
    }
}

int checkMap() {
    int x = 0, y = 0;
    int count = 0;

    for (int i = 0; i < map.size(); i++)
    {
        for (int j = 0; j < map[0].size(); j++)
        {
            if (map[i][j] == 1) {
                dfs(i, j);
                count++;
            }
        }
        
    }

    return count;
}

int main () {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    cin >> T;
    
    int m, n, k;
    int x, y;

    for (int i = 0; i < T; i++)
    {
        cin >> m >> n >> k;
        map.resize(m, vector<int>(n, 0));

        for (int j = 0; j < k; j++)
        {
            cin >> x >> y;
            map[x][y] = 1;
        }
        
        cout << checkMap() << endl;

        map.clear();
    }

    return 0;
}

