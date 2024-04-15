#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> list;
bool isUsed[9] = {false};

void comb(int idx, int k) {
    if (k == M) {
        for (int i = 0; i < M; i++)
        {
            cout << list[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = idx+1; i <= N; i++)
    {
        // cout << "k=" << k << " i=" << i << endl;
        if (!isUsed[i]) {
            list[k] = i;
            isUsed[i] = true;
            comb(i, k+1);
            isUsed[i] = false;

        }
    }
}

// void get_combination(int idx, int depth) {
//     if(depth == r) {
//         for(int i=0; i<n; i++) {
//             if(visited[i]) {
//                 cout << visited[i];
//             }
//         }
//     }

//     for(int i=idx; i<n; i++) {
//         if(!visited[i]) {
//             visited[i] = true;
//             get_combination(i, depth + 1);
//             visited[i] = false;
//         }
//     }
// }

int main() {
    cin >> N >> M;
    list.resize(M, 0);
    comb(0, 0);
}