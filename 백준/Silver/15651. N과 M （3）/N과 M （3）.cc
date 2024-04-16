/** Backtracking */
/** 중복순열 */

#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> list;

void repeatPerm(int depth) {
    if (depth == M) {
        for (int i = 0; i < M; i++)
        {
            cout << list[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= N; i++)
    {
        list[depth] = i;
        repeatPerm(depth+1);
    }
    
}

int main() {
    cin >> N >> M;
    list.resize(M, 0);
    repeatPerm(0);

    return 0;
}