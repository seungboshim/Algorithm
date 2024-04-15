#include <iostream>

using namespace std;

int N, M;
int list[9];
bool isUsed[9];

void func(int k) {
    if (k==M) {
        for (int i = 0; i < M; i++)
        {
            cout << list[i] << " ";
        }
        cout << "\n";
    }

    for (int i = 1; i <= N; i++)
    {
        if (!isUsed[i]) {
            list[k] = i;
            isUsed[i] = true;
            func(k+1);
            isUsed[i] = false;
        }
    }
    
}

int main() {
    cin >> N >> M;

    func(0);

    return 0;
}