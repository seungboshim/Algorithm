/** Backtracking */
/** 조합+중복순열? */

#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> list;

void comb(int idx, int depth) {
    if (depth == M) {
        for (int i = 0; i < M; i++)
        {
            cout << list[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = idx; i <= N; i++)
    {
        list[depth] = i;
        comb(i, depth+1);
    }
    
}

int main() {
    cin >> N >> M;
    list.resize(M);
    comb(1, 0);
    return 0;
}